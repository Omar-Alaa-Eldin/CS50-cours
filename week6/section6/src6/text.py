text = "   IN the great green RooM   "
# removing the white spaces from the either end.
text = text.strip()
# convert the text to lower case
text = text.lower()
# convrt frist char to upper case.
text = text.capitalize()
# split string to list of words, by defult it splited by space " ", or we can input a spliter as argument.
words = text.split()

# Round 0
print("Round 0")
print(words, end="\n\n") # insert an empty line after this line

# Round 1
print("Round 1")
for word in words:
    print(word)
print()

# Round 2
print("Round 2")
for word in words:
    for _ in word:
        print(_)
print()

# Round 3
print("Round 3")
for word in words:
    if "g" in word:
        print(word)
print()

# Round 4
print("Round 4")
for word in words[2:]:
    print(word)
print()

# Round 5
print("Round 5")
for word in words:
    print("Goodnight Moon")
print()