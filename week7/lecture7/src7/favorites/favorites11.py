# Searches database popularity of a problem

import csv

from cs50 import SQL

# Open database
db = SQL("sqlite:///favorites.db")

# Prompt user for favorite
favorite = input("Favorite: ")

'''
# Search for title
rows = db.execute("select * from favorites where problem = 'Mario'")

for row in rows:
    print(row["language"])
'''
'''
rows = db.execute("select count(*) as n from favorites where problem = 'Mario'")

print(rows[0]["n"])

row = rows[0]
print(row["n"])
'''
'''
rows = db.execute("select count(*) as n from favorites where problem =?", favorite)
print(rows[0]["n"])
'''


rows = db.execute("SELECT COUNT(*) FROM favorites WHERE problem LIKE ?", "%" + favorite + "%")

# Get first (and only) row
row = rows[0]
print(rows)
# Print popularity
print(row["COUNT(*)"])
