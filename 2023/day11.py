from itertools import combinations, product
from bisect import bisect

with open("./day11.txt") as f:
    inps = [list(line.rstrip()) for line in f]

expand_rows: list[int] = []
expand_columns: list[int] = []

for i in range(len(inps)):
    for j in range(len(inps[0])):
        if inps[i][j] == "#":
            break
    else:
        expand_rows.append(i)
expand_rows.sort()

for j in range(len(inps[0])):
    for i in range(len(inps)):
        if inps[i][j] == "#":
            break
    else:
        expand_columns.append(j)
expand_columns.sort()

galaxies = [
    (i, j)
    for i, j in product(range(len(inps)), range(len(inps[0])))
    if inps[i][j] == "#"
]


def calc_dist(factor: int) -> int:
    sum = 0
    factor -= 1
    for g1, g2 in combinations(galaxies, 2):
        [x1, x2], [y1, y2] = map(sorted, zip(g1, g2))
        rexp = bisect(expand_rows, x2) - bisect(expand_rows, x1)
        cexp = bisect(expand_columns, y2) - bisect(expand_columns, y1)

        sum += factor * (rexp + cexp) + x2 - x1 + y2 - y1

    return sum


print(calc_dist(2))
print(calc_dist(1000_000))
