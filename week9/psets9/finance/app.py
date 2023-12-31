import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


def valid(field):
    if not request.form.get(field):
        return apology(f"must provide {field}", 400)


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    rows = db.execute(
        """
                select symbol, sum(shares) as totalshares
                from transactions
                where user_id = :user_id
                group by symbol
                having totalshares > 0
               """,
        user_id=session["user_id"],
    )
    holdings = []
    grand_total = 0
    for row in rows:
        stock = lookup(row["symbol"])
        holdings.append(
            {
                "symbol": stock["symbol"],
                "name": stock["name"],
                "shares": row["totalshares"],
                "price": usd(stock["price"]),
                "total": usd(stock["price"] * row["totalshares"]),
            }
        )
        grand_total += stock["price"] * row["totalshares"]

    rows = db.execute(
        "select cash from users where id=:user_id", user_id=session["user_id"]
    )
    cash = rows[0]["cash"]
    grand_total = grand_total + cash

    return render_template(
        "index.html", holdings=holdings, grand_total=usd(grand_total), cash=usd(cash)
    )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        check = valid("symbol") or valid("shares")
        if check:
            return check
        elif not request.form.get("shares").isdigit():
            return apology("invalid number of shares")
        symbol = request.form.get("symbol").upper()
        shares = int(request.form.get("shares"))
        stock = lookup(symbol)
        if stock is None:
            return apology("invalid symbol")
        rows = db.execute(
            "SELECT cash FROM users WHERE id=:user_id", user_id=session["user_id"]
        )
        cash = rows[0]["cash"]

        result = cash - shares * stock["price"]
        if result < 0:
            return apology("can't afford")
        db.execute(
            "UPDATE users SET cash=:result WHERE id=:id",
            result=result,
            id=session["user_id"],
        )
        db.execute(
            """
            INSERT INTO transactions (user_id, symbol, shares, price)
            VALUES (:user_id, :symbol, :shares, :price)
            """,
            user_id=session["user_id"],
            symbol=stock["symbol"],
            shares=shares,
            price=stock["price"],
        )
        flash("Bought!")
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    data = db.execute(
        """   select symbol, shares, price, transacted
            from transactions
            where user_id=:user_id
            """,
        user_id=session["user_id"],
    )
    for i in range(len(data)):
        data[i]["price"] = usd(data[i]["price"])
    return render_template("histroy.html", data=data)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        check = valid("username") or valid("password")
        if check is not None:
            return check

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        check = valid("symbol")
        if check != None:
            return check
        symbol = request.form.get("symbol").upper()
        stock = lookup(symbol)
        if stock == None:
            return apology("invalid symbol", 400)
        return render_template(
            "quoted.html",
            stockname={
                "name": stock["name"],
                "symbol": stock["symbol"],
                "price": usd(stock["price"]),
            },
        )
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        check = valid("username") or valid("password") or valid("confirmation")
        if check is not None:
            return check
        if request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords must mach", 400)
        try:
            key = db.execute(
                "INSERT INTO users (username, hash) VALUES (:username, :hash)",
                username=request.form.get("username"),
                hash=generate_password_hash(request.form.get("password")),
            )
        except:
            return apology("user name exists", 400)
        if key is None:
            return apology("user name exists", 400)
        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        check = valid("symbol") or valid("shares")
        if check:
            return check
        elif not request.form.get("shares").isdigit():
            return apology("invalid number of shares")
        symbol = request.form.get("symbol").upper()
        shares = int(request.form.get("shares"))
        stock = lookup(symbol)
        if stock is None:
            return apology("invalid symbol")
        rows = db.execute(
            """ select symbol, sum(shares) as totalshares
                   from transactions
                   where user_id=:user_id
                    group by symbol
                    having totalshares >0; """,
            user_id=session["user_id"],
        )
        for row in rows:
            if row["symbol"] == symbol:
                if shares > row["totalshares"]:
                    return apology("too many")

        rows = db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])
        cash = rows[0]["cash"]

        result = cash + shares * stock["price"]

        db.execute(
            "UPDATE users SET cash=:result WHERE id=:id",
            result=result,
            id=session["user_id"],
        )
        db.execute(
            """
            INSERT INTO transactions (user_id, symbol, shares, price)
            VALUES (:user_id, :symbol, :shares, :price)
            """,
            user_id=session["user_id"],
            symbol=stock["symbol"],
            shares=-1 * shares,
            price=stock["price"],
        )
        flash("Sold!")
        return redirect("/")
    else:
        rows = db.execute(
            """
        select symbol
        from transactions
        where user_id=:user_id
        group by symbol
        having sum(shares) > 0;
        """,
            user_id=session["user_id"],
        )
        return render_template("sell.html", symbols=[row["symbol"] for row in rows])
