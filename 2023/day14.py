from itertools import starmap
from hashlib import sha1
from tqdm import trange

mirror = list(
    map(
        lambda line: list(map(lambda c: {"O": 1, "#": 2, ".": 0}[c], line.rstrip())),
        open("./day14.txt"),
    )
)


def north():
    swap = True
    while swap:
        swap = False
        for j in range(len(mirror[0])):
            for i in range(len(mirror) - 1):
                if mirror[i][j] == 0 and mirror[i + 1][j] == 1:
                    swap = True
                    mirror[i][j] = 1
                    mirror[i + 1][j] = 0


def south():
    swap = True
    while swap:
        swap = False
        for j in range(len(mirror[0])):
            for i in range(len(mirror) - 1):
                if mirror[i][j] == 1 and mirror[i + 1][j] == 0:
                    swap = True
                    mirror[i][j] = 0
                    mirror[i + 1][j] = 1


def west():
    swap = True
    while swap:
        swap = False
        for i in range(len(mirror)):
            for j in range(len(mirror[0]) - 1):
                if mirror[i][j] == 0 and mirror[i][j + 1] == 1:
                    swap = True
                    mirror[i][j + 1] = 0
                    mirror[i][j] = 1


def east():
    swap = True
    while swap:
        swap = False
        for i in range(len(mirror)):
            for j in range(len(mirror[0]) - 1):
                if mirror[i][j] == 1 and mirror[i][j + 1] == 0:
                    swap = True
                    mirror[i][j + 1] = 1
                    mirror[i][j] = 0


def cycle():
    north()
    west()
    south()
    east()


def north_beam_load():
    return sum(
        starmap(
            lambda i, m: (i + 1) * sum(map(lambda e: e == 1, m)),
            enumerate(reversed(mirror)),
        )
    )


def show():
    for m in mirror:
        print(*map(lambda i: {1: "O", 2: "#", 0: "."}[i], m), sep="")
    print()


north()
print(north_beam_load())
west()
south()
east()


def hash_current():
    return sha1(b"".join(map(bytearray, mirror)), usedforsecurity=False).hexdigest()


loads = [north_beam_load()]
seen = [hash_current()]
for i in trange(1_000_000_000):
    cycle()
    if hash_current() in seen:
        break
    seen.append(hash_current())
    loads.append(north_beam_load())

cycle_start = seen.index(hash_current())
cycle_length = len(loads) - cycle_start
print(loads[cycle_start + (1_000_000_000 - cycle_start - 1) % cycle_length])
