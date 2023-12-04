# Prints all favorites in CSV using csv.reader

import csv

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create reader
    reader = csv.reader(file)

    # Skip header row
    next(reader) # move for the second row of the file to skip the header

    # Iterate over CSV file, printing each favorite
    for row in reader:
        print(row[1])
