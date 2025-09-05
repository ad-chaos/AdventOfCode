from itertools import combinations_with_replacement

with open("./input2.txt") as f:
    checksum = 0
    for line in f.readlines():
        row = sorted(map(int, line.rstrip().split("\t")))
        for i in combinations_with_replacement(row, 2):
            q, r = divmod(max(i), min(i))
            if not r and q^1:
                checksum += q
print(checksum)
