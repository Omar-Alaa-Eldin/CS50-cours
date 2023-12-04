credit = input("Number: ")

lis = credit[::-1]

"""
sum1 = sum([int(x) for x in lis[0: :2]])
sum2 = sum ([(int(x) * 2) // 10 + ((int(x) * 2 ) % 10) for x in lis[1: :2]])

print(lis)
print(sum1)
print(sum2)
"""
sum = sum([int(x) for x in lis[0::2]]) + sum(
    [(int(x) * 2) // 10 + ((int(x) * 2) % 10) for x in lis[1::2]]
)
print(sum)
if sum % 10 == 0:
    if len(credit) == 15 and credit[0:2] in ["34", "37"]:
        print("AMEX")
    elif len(credit) == 16 and 51 <= int(credit[0:2]) <= 55:
        print("MASTERCARD")
    elif len(credit) in [13, 16] and credit[0] == "4":
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
