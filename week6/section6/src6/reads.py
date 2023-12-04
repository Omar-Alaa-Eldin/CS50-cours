import csv

books = []

# Add books to your shelf by reading from books.csv
with open("books.csv") as file:
    '''
    text = file.read()
    print(text, end="\n\n")
    '''

    text = csv.reader(file)
    for row in text:
        print(row, end="\n\n")
        print(row[0])

    '''
    file_reader = csv.DictReader(file)
    for book in file_reader:
        print(book, end="\n\n")
    '''
    '''
    file_reader = csv.DictReader(file)
    for book in file_reader:
        #books.append(book)
        print(book["\ufefftitle"])
    '''

# Print titles of books
'''
for book in books:
    print(book["\ufefftitle"])
'''