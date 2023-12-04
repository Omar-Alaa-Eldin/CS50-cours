# Saves names and numbers to a CSV file using a DictWriter

import csv

# Get name and number
name = input("Name: ")
number = input("Number: ")

# Open CSV file
with open("phonebook.csv", "a") as file:

    # Print to file
    # use dictwriter to avoid the wape of cloum information when writeing it.
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    # insert the information in any order and it will inserted in right column
    writer.writerow({"number": number, "name": name})
