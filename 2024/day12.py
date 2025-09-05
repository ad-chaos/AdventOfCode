from pathlib import Path
from itertools import starmap, chain


class GardenPlot:
    def __init__(self, ty):
        self.ty = ty
        self.outsiders = []

    def perimeter(self):
        return len(self.outsiders)

    def __hash__(self):
        return ord(self.ty)


def parsed(strings):
    return [[GardenPlot(p) for p in string] for string in strings]


def real_data():
    return parsed(Path("input12.txt").read_text().strip().split("\n"))


def test_data():
    return parsed(
        """RRRRIICCFF
RRRRIICCCF
VVRRRCCFFF
VVRCCCJFFF
VVVVCJJCFE
VVIVCCJJEE
VVIIICJJEE
MIIIIIJJEE
MIIISIJEEE
MMMISSJEEE""".split("\n")
    )


def prepare_grid(grid: list[GardenPlot]):
    mx, my = len(grid), len(grid[0])

    for x, row in enumerate(grid):
        for y, plot in enumerate(row):
            for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nx = x + dx
                ny = y + dy
                if not (
                    0 <= nx < mx and 0 <= ny < my and grid[x][y].ty == grid[nx][ny].ty
                ):
                    plot.outsiders.append(((nx, ny), (-dy, dx)))

    return grid


def gen_plots(grid: list[GardenPlot]):
    mx, my = len(grid), len(grid[0])

    seen_plots = set()

    def find_region(x, y):
        for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nx = x + dx
            ny = y + dy
            if (
                0 <= nx < mx
                and 0 <= ny < my
                and (nx, ny) not in seen_plots
                and grid[x][y].ty == grid[nx][ny].ty
            ):
                seen_plots.add((nx, ny))
                find_region(nx, ny)

    seen_regions = set()
    for i, row in enumerate(grid):
        for j, plot in enumerate(row):
            if (i, j) not in seen_regions:
                seen_plots.clear()
                seen_plots.add((i, j))
                find_region(i, j)
                seen_regions.update(seen_plots)

                yield seen_plots, plot.ty


def part1(grid: list[GardenPlot]):
    cost = 0
    for plot, _ in gen_plots(grid):
        cost += len(plot) * sum(starmap(lambda x, y: grid[x][y].perimeter(), plot))
    return cost


def part2(grid: list[GardenPlot]):
    cost = 0
    for plot, ty in gen_plots(grid):
        outsiders = sorted(
            chain.from_iterable(starmap(lambda x, y: grid[x][y].outsiders, plot))
        )
        boundary = 0
        for (x, y), (dx, dy) in outsiders:
            if ((x+dx, y+dy),(dx, dy)) not in outsiders:
                boundary += 1
        cost += len(plot) * boundary
    return cost


grid = prepare_grid(real_data())
print("Part 1:", part1(grid))
print("Part 2:", part2(grid))
