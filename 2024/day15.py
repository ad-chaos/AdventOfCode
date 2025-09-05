from itertools import chain
from copy import deepcopy
from pathlib import Path


def parsed(strings):
    split = strings.index("")
    grid = list(map(list, strings[:split]))
    moves = strings[split + 1 :]
    return grid, list(chain.from_iterable(moves))


def real_data():
    return parsed(Path("input15.txt").read_text().strip().splitlines())


def test_data():
    return parsed(
        """##########
#..O..O.O#
#......O.#
#.OO..O.O#
#..O@..O.#
#O#..O...#
#O..O..O.#
#.OO.O.OO#
#....O...#
##########

<vv>^<v^>v>^vv^v>v<>v^v<v<^vv<<<^><<><>>v<vvv<>^v^>^<<<><<v<<<v^vv^v>^
vvv<<^>^v^^><<>>><>^<<><^vv^^<>vvv<>><^^v>^>vv<>v<<<<v<^v>^<^^>>>^<v<v
><>vv>v^v^<>><>>>><^^>vv>v<^^^>>v^v^<^^>v^^>v^<^v>v<>>v^v^<v>v^^<^^vv<
<<v<^>>^^^^>>>v^<>vvv^><v<<<>^^^vv^<vvv>^>v<^^^^v<>^>vvvv><>>v^<<^^^^^
^><^><>>><>^^<<^^v>>><^<v>^<vv>>v>>>^v><>^v><<<<v>>v<v<v>vvv>^<><<>^><
^>><>^v<><^vvv<^^<><v<<<<<><^v<<<><<<^^<v<^^^><^>>^<v^><<<^>>^v<v^v<v^
>^>>^v>vv>^<<^v<>><<><<v<<v><>v<^vv<<<>^^v^>^^>>><<^v>>v^v><^^>>^<>vv^
<><^^>^^^<><vvvvv^v<v<<>^v<v>v<<^><<><<><<<^^<<<^<<>><<><^^^>^^<>^>v<>
^^>vv<^v^v<vv>^<><v<^v>^^^>>>^^vvv^>vvv<>>>^<^>>>>>^<<^v>^vvv<>^<><<v>
v^^>>><<^^<>>^v^<v^vv<>v^<<>^<^v^v><^<<<><<^<v><v<>vv>>v><v^<vv<>v^<<^""".splitlines()
    )


movemap = {"<": (0, -1), ">": (0, 1), "^": (-1, 0), "v": (1, 0)}


def red(c, t):
    return f"\033[38;5;{t}m{c}\033[0m"  # ]]


def gprint(grid, pusher=None, pushing=None):
    def fmt(c, at):
        if pusher is not None and at == pusher:
            return red(c, 10)
        if pushing is not None and at == pushing:
            return red(c, 1)
        return c

    for i, row in enumerate(grid):
        for j, e in enumerate(row):
            print(end=fmt(e, (i, j)))
        print()


def get_coord_sum(grid, box):
    coords = 0
    for i, row in enumerate(grid):
        for j, tile in enumerate(row):
            if tile == box:
                coords += 100 * i + j
    return coords


def locate_bot(grid):
    for i, row in enumerate(grid):
        for j, p in enumerate(row):
            if p == "@":
                return i, j


def part1(grid, moves):
    x, y = locate_bot(grid)

    def shift(x, y, dx, dy):
        nx, ny = x + dx, y + dy
        if grid[nx][ny] == "O":
            shift(nx, ny, dx, dy)
        if grid[nx][ny] == ".":
            grid[x][y], grid[nx][ny] = grid[nx][ny], grid[x][y]
            return nx, ny
        return x, y

    for move in moves:
        dx, dy = movemap[move]
        if grid[x + dx][y + dy] != "#":
            x, y = shift(x, y, dx, dy)

    return get_coord_sum(grid, "O")


def part2(grid, moves):
    x, y = locate_bot(grid)
    partner = {"[": 1, "]": -1}

    def shift(x, y, dx, dy):
        nx, ny = x + dx, y + dy

        if grid[nx][ny] in "[]":
            dpy = partner[grid[nx][ny]]
            shift(nx, ny, dx, dy)
            if dx:
                shift(nx, ny + dpy, dx, dy)

        if grid[nx][ny] == ".":
            grid[x][y], grid[nx][ny] = grid[nx][ny], grid[x][y]
            return nx, ny

        return x, y

    def can_shift(x, y, dx, dy):
        nx, ny = x + dx, y + dy

        if grid[nx][ny] in "[]":
            dpy = partner[grid[nx][ny]]
            return (
                can_shift(nx, ny, dx, dy) and can_shift(nx, ny + dpy, dx, dy)
                if dx
                else True
            )

        if grid[nx][ny] == ".":
            return True

        return False

    for move in moves:
        dx, dy = movemap[move]
        if grid[x + dx][y + dy] != "#":
            if can_shift(x, y, dx, dy):
                x, y = shift(x, y, dx, dy)

    return get_coord_sum(grid, "[")  # ]


def expand_grid(grid):
    expand_map = {".": "..", "#": "##", "O": "[]", "@": "@."}
    return [list(chain.from_iterable(expand_map[t] for t in row)) for row in grid]


grid, moves = real_data()
print("Part 1:", part1(deepcopy(grid), moves))
print("Part 2:", part2(expand_grid(grid), moves))
