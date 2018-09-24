import sys

with open(sys.argv[1]) as fh:
    for line in fh.readlines():
        nums = map(int, (" ".join(line.split()).split()))
        print(list(nums))
