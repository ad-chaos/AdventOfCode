from collections import defaultdict
from itertools import combinations, count
from pathlib import Path


def parsed(strings):
    ans = defaultdict(list)
    for i, string in enumerate(strings):
        for j, e in enumerate(string):
            if e != ".":
                ans[e].append((i, j))
    return ans, len(strings), len(strings[0])


def real_data():
    return parsed(Path("input8.txt").read_text().strip().split("\n"))


def test_data():
    return parsed(
        """............
........0...
.....0......
.......0....
....0.......
......A.....
............
............
........A...
.........A..
............
............""".split()
    )


def get_antennas(data):
    for freq, coords in data.items():
        for t1, t2 in combinations(coords, 2):
            x1, y1 = t1
            x2, y2 = t2
            yield x1, y1, x2, y2
            yield x2, y2, x1, y1

def part1():
    data, mx, my = real_data()
    antinodes = set()
    for x1, y1, x2, y2 in get_antennas(data):
        x3 = 2*x2 - x1
        y3 = 2*y2 - y1
        if 0<=x3<mx and 0<=y3<my:
            antinodes.add((x3, y3))

    return len(antinodes)

def part2():
    data, mx, my = real_data()
    antinodes = set()
    for x1, y1, x2, y2 in get_antennas(data):
        for t in count():
            x3 = x1 + t*(x2-x1)
            y3 = y1 + t*(y2-y1)
            if 0<=x3<mx and 0<=y3<my:
                antinodes.add((x3, y3))
            else:
                break

    return len(antinodes)

print("Part 1:", part1())
print("Part 2:", part2())
