import sys
if len(sys.argv) != 2:
    print("Missing command-line argument")
    # exit the program and return 1
    sys.exit(1)

print(f"hello, {sys.argv[1]}")
sys.exit(0)