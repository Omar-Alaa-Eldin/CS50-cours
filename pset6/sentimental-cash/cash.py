# TODO


def main():
    price = get_price()
    cents = int(price * 100)
    # print(cents)
    quarters = calculate_quarters(cents)
    cents -= quarters * 25
    # print(quarters)
    dimes = calculate_dimes(cents)
    cents -= dimes * 10
    nickels = calculate_nickels(cents)
    cents -= nickels * 5
    # pennies = calculate_pennies(cents)

    coins = quarters + dimes + nickels + cents
    print(coins)


def calculate_quarters(cents):
    q = cents // 25
    return q


def calculate_dimes(cents):
    d = cents // 10
    return d


def calculate_nickels(cents):
    n = cents // 5
    return n


"""
def calculate_pennies(cents):
    p = cents // 1
    return p
"""


def get_price():
    while True:
        try:
            n = float(input("Change owed: "))
            if n > 0:
                return n
        except ValueError:
            print("Not an integer")


main()
