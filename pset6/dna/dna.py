import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        # exit the program and return 1
        sys.exit(1)
    # TODO: Read database file into a variable
    samples = []
    with open(sys.argv[1]) as data:
        data_reader = csv.DictReader(data)
        for x in data_reader:
            samples.append(x)
    # for s in samples:
    # print(s)
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as test_sample:
        test = test_sample.read()
    # print(test)
    # TODO: Find longest match of each STR in DNA sequence
    scan = []
    with open(sys.argv[1]) as data:
        check = csv.reader(data)
        for r in check:
            for i in r:
                scan.append(i)
            break
    scan = scan[1::]
    # print(scan)
    result = {}
    for i in scan:
        result[i] = longest_match(test, i)
        # print(result[i])
    # print(result)
    # TODO: Check database for matching profiles
    stat = True
    for i in samples:
        for x in scan:
            # print(x, result[x], i[x])
            if int(result[x]) == int(i[x]):
                stat = True
                # print(stat)
            else:
                stat = False
                break

        if stat == True:
            print(i["name"])
            break

    if stat == False:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
