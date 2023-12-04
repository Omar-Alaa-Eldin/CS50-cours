# TODO


def main():
    height = get_height()
    for i in range(1, height + 1):
        # print(i)
        print(" " * (height - i) + "#" * (i))


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0 and n < 9:
                return n
        except ValueError:
            print("Not an integer")


main()
