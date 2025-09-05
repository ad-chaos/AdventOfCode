from functools import reduce
from itertools import zip_longest
from operator import add

from more_itertools import sliding_window

fp_x, fp_y = (500, 0)
with open("./input14.txt") as f:
    paths = list(
        map(
            lambda points: list(
                map(lambda point: tuple(map(int, point.split(","))), points)
            ),
            map(lambda line: line.rstrip().split(" -> "), f),
        )
    )

max_x = 0
max_y = 0
min_x, min_y = fp_x, fp_y

for path in paths:
    for (x1, y1), (x2, y2) in sliding_window(path, 2):
        min_x = min(min_x, x1, x2)
        min_y = min(min_y, y1, y2)

        max_x = max(max_x, x1, x2)
        max_y = max(max_y, y1, y2)

offset = 1
breadth = max_x - min_x + 1 + 2 * offset
length = max_y - min_y + 1 + 2 * offset
num_rows = max_y - min_y + 2
sands = [[0 for _ in range(breadth)] for _ in range(length)]


for path in paths:
    for (x1, y1), (x2, y2) in sliding_window(path, 2):
        sign_x = (-1) ** (x1 > x2)
        sign_y = (-1) ** (y1 > y2)
        fillvalue = y1 if y1 == y2 else x1
        for x, y in zip_longest(
            range(x1, x2 + sign_x, sign_x),
            range(y1, y2 + sign_y, sign_y),
            fillvalue=fillvalue,
        ):
            sands[y - min_y + offset][x - min_x + offset] = 1

num_walls = reduce(add, reduce(add, sands))

sands[fp_y - min_y + offset][fp_x - min_x + offset] = 2


def show():
    for sand in sands:
        for particle in sand:
            print(end=[".", "#", "+", "o"][particle])
        print()


def access(x, y):
    try:
        return sands[x + offset][y + offset]
    except IndexError:
        # Part 1:
        # print(sand_particles); exit(0)
        return 1


sand_particles = 0
sx, sy = fp_y - min_y, fp_x - min_x
whole_pyramid = (len(sands) + 2) ** 2

while True:
    if access(sx + 1, sy) != 1:
        sx += 1
    elif access(sx + 1, sy - 1) != 1:
        sx += 1
        sy -= 1
    elif access(sx + 1, sy + 1) != 1:
        sx += 1
        sy += 1
    else:
        if sx == fp_y - min_y and sy == fp_x - min_x:
            sands[sx + offset][sy + offset] = 1
            break
        sands[sx + offset][sy + offset] = 1
        sx, sy = fp_y - min_y, fp_x - min_x
        sand_particles += 1

del sands[0]
for i in range(len(sands)):
    j = -1
    while sands[i][j] == 0:
        del sands[i][j]
    j = 0
    while sands[i][j] == 0:
        del sands[i][j]

# Part 2: basically full triangle - walls - voids
print(
    num_rows**2 - num_walls - sum(map(lambda x: x == 0, reduce(add, sands)))
)
