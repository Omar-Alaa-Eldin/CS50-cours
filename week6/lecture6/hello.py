from cs50 import get_string

print("hello, world")

answer = get_string("what's your name? ")
#concatenate strings by '+' operator.
print("hello, " + answer)
#print formated string.
print(f"hello, {answer}")