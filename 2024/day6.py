from tqdm import tqdm


def gen_grid(string):
    return list(map(list, string.split()))


def to_string(grid):
    return "\n".join(map("".join, grid))


def test_data():
    return gen_grid(
        """....#.....
    .........#
    ..........
    ..#.......
    .......#..
    ..........
    .#..^.....
    ........#.
    #.........
    ......#..."""
    )


def real_data():
    from pathlib import Path

    return gen_grid(Path("input6.txt").read_text())


class Walker:
    def __init__(self, data: list[list[str]]):
        self.grid = data
        self.start = self.get_start()
        self.curr = self.start
        self.dxy = (-1, 0)
        self.seen: set[tuple[tuple[int, int], tuple[int, int]]] = set()

    def get_start(self) -> tuple[int, int]:
        for i, row in enumerate(self.grid):
            for j, char in enumerate(row):
                if char == "^":
                    return i, j
        assert False

    def step(self):
        x, y = self.curr
        dx, dy = self.dxy
        if self.grid[x][y] != "#":
            self.seen.add((self.dxy, self.curr))
            self.grid[x][y] = "X"
            self.curr = (x + dx, y + dy)
        else:
            self.curr = (x - dx, y - dy)
            self.dxy = (dy, -dx)

    def within_bounds(self):
        x, y = self.curr
        return 0 <= x < len(self.grid) and 0 <= y < len(self.grid[0])

    def simulate(self):
        while self.within_bounds():
            self.step()
            if (self.dxy, self.curr) in self.seen:
                return True
        return False

    def reset(self):
        self.seen.clear()
        self.curr = self.start
        self.dxy = (-1, 0)


def part1(wk: Walker) -> tuple[int, set[tuple[int, int]]]:
    from operator import itemgetter

    wk.reset()
    wk.simulate()
    return sum(x.count("X") for x in wk.grid), set(map(itemgetter(1), wk.seen))


def part2(wk: Walker, candidates: set[tuple[int, int]]) -> int:
    wk.reset()
    loops = 0
    for i, j in tqdm(candidates, leave=False):
        wk.grid[i][j] = "#"
        if wk.simulate():
            loops += 1
        wk.reset()
        wk.grid[i][j] = "."

    return loops


wk = Walker(real_data())
ans, tocheck = part1(wk)
print("Part 1:", ans)
print("Part 2:", part2(wk, tocheck))
