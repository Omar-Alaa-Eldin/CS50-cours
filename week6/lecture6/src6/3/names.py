# Implements linear search for names

import sys

# A list of names
names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]

# Ask for name
name = input("Name: ")


"""
make search manually one by one using linear search
for n in names:
    if name == n:
        print("Found")
        sys.exit(0)
"""

# Search for name without creat loop by using linear search

if name in names:
    print("Found")
    sys.exit(0)

print("Not found")
sys.exit(1)
