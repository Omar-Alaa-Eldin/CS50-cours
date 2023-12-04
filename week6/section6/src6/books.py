books = []

# Add three books to your shelf
for i in range(3):
    book = dict()
    book["title"] = input("Title: ").strip().capitalize()
    book["author"] = input("Author: ")

    books.append(book)

# Print book titles

print(books, end="\n\n")


for book in books:
    print(book["title"])

for book in books:
    print(book["author"])