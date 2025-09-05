from itertools import pairwise
from pathlib import Path
from time import sleep


def parsed(strings):
    return [list(string) for string in strings]


def real_data():
    return parsed(Path("input16.txt").read_text().splitlines())


def test_data():
    return parsed(
        """#################
#...#...#...#..E#
#.#.#.#.#.#.#.#.#
#.#.#.#...#...#.#
#.#.#.#.###.#.#.#
#...#.#.#.....#.#
#.#.#.#.#.#####.#
#.#...#.#.#.....#
#.#.#####.#.###.#
#.#.#.......#...#
#.#.###.#####.###
#.#.#...#.....#.#
#.#.#.#####.###.#
#.#.#.........#.#
#.#.#.#########.#
#S#.............#
#################""".split("\n")
    )


def locate_start(grid):
    start = 0, 0
    for i, row in enumerate(grid):
        for j, p in enumerate(row):
            if p == "S":
                return (i, j)

    return start


def evaluate_path(path):
    score = len(path) - 1
    for d1, d2 in pairwise(path):
        if d1 != d2:
            score += 1000
    return score


def red(c, t):
    return f"\033[38;5;{t}m{c}\033[0m"  # ]]


def print_path(grid, path, pcolor = 10):
    for i, row in enumerate(grid):
        for j, p in enumerate(row):
            if (i, j) in path:
                print(end=red("██", pcolor))
            else:
                print(
                    end={
                        ".": "  ",
                        "#": red("██", 1),
                        "E": red("██", 14),
                        "S": red("██", 14),
                    }[p]
                )
        print()
    print()


def backtracker(grid):
    path = []
    seen = set()
    minscore = None

    def dfs(x, y):
        nonlocal minscore
        if grid[x][y] == "E":
            score = evaluate_path([(0, 1)] + path)
            if minscore is None:
                minscore = score
            minscore = min(minscore, score)
            return

        for dx, dy in ((0, 1), (1, 0), (0, -1), (-1, 0)):
            nx, ny = x + dx, y + dy
            if (nx, ny) in seen:
                continue
            if grid[nx][ny] == "#":
                continue

            seen.add((nx, ny))
            path.append((dx, dy))
            dfs(nx, ny)
            seen.remove((nx, ny))
            path.pop()

    dfs(*locate_start(grid))
    print(minscore)


def backtracker_loop(grid):
    sx, sy = locate_start(grid)

    path = []
    dpath = []
    seen = set()
    stack = [(0, sx, sy, 0, 1)]
    old_lvl = -1
    minscore = None
    while stack:
        lvl, x, y, dx, dy = stack.pop()
        for _ in range(old_lvl - lvl):
            seen.remove(path.pop())
            dpath.pop()
        old_lvl = lvl

        if (x, y) in seen:
            continue

        seen.add((x, y))
        path.append((x, y))
        dpath.append((dx, dy))

        if grid[x][y] == "E":
            print("\033[H")  # ]
            print_path(grid, path, 14)
            sleep(0.5)
            score = evaluate_path(dpath)
            if minscore is None:
                minscore = score
            minscore = min(minscore, score)
            seen.remove(path.pop())
            dpath.pop()
            continue

        if grid[x][y] == "#":
            seen.remove(path.pop())
            dpath.pop()
            continue

        print("\033[H")  # ]
        print_path(grid, path)
        sleep(0.2)

        for dx, dy in ((0, 1), (1, 0), (0, -1), (-1, 0)):
            nx, ny = x + dx, y + dy
            stack.append((lvl + 1, nx, ny, dx, dy))


grid = test_data()
start = locate_start(grid)
backtracker_loop(grid)
