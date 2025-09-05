from pathlib import Path
from itertools import product
from operator import add

keys = []
locks = []
for scheme in Path("input25.txt").read_text().split("\n\n"):
    lst = scheme.strip().split()
    t = []
    for i in range(len(lst[0])):
        trp = ''
        for j in range(len(lst)):
            trp += lst[j][i]
        t.append(trp)
    if "".join(lst[0]) == "#####":
        locks.append(t)
    else:
        keys.append(t)

count = 0
def count_height(way):
    return way.count("#")

for k1, l1 in product(keys, locks):
    count += all(map(lambda e: e <= 7, map(add, map(count_height, k1), map(count_height, l1))))
print("Part 1:", count)
