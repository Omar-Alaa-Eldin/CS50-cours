# Floating-point imprecision

# Prompt user for x
# input function return string by defulte
x = int(input("x: "))

# Prompt user for y
y = int(input("y: "))

# Divide x by y
z = x / y
# increas the number after floating point to br 50 number.
# it produce to floating point imprecision
# thir is no integer overflow in python
print(f"{z:.50f}")
