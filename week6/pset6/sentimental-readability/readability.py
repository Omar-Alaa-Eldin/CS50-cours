text = input("text: ")

letters, sentences, words = 0, 0, 1

for char in text:
    if char.isalpha():
        letters += 1
    if char.isspace():
        words += 1
    if char in ["?", ".", "!"]:
        sentences += 1

L = (letters * 100) / words
S = (sentences * 100) / words
result = 0.0588 * L - 0.296 * S - 15.8

if result > 16:
    print("Grade 16+")
elif result < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(result)}")
