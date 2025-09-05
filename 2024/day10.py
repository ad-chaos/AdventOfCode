from pathlib import Path

# Can use MagicMock but this is Faster
class UniversalSet:
    def __init__(self):
        pass

    def add(self, item):
        pass

    def clear(self):
        pass

    def __contains__(self, item):
        return False


def parsed(strings):
    return [[int(x) for x in string] for string in strings]


def real_data():
    return parsed(Path("input10.txt").read_text().strip().split("\n"))


def test_data():
    return parsed(
        """89010123
78121874
87430965
96549874
45678903
32019012
01329801
10456732""".split("\n")
    )


def find_all_trails(grid, bookkeeper):
    mx, my = len(grid), len(grid[0])
    visited = bookkeeper()

    def find_trailscore(x, y):
        if grid[x][y] == 9:
            return 1
        score = 0
        for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nx = x + dx
            ny = y + dy
            if (
                0 <= nx < mx
                and 0 <= ny < my
                and (nx, ny) not in visited
                and grid[nx][ny] - grid[x][y] == 1
            ):
                visited.add((nx, ny))
                score += find_trailscore(nx, ny)
        return score

    scores = 0
    for i, row in enumerate(grid):
        for j, height in enumerate(row):
            if height == 0:
                visited.clear()
                visited.add((i, j))
                scores += find_trailscore(i, j)

    return scores


data = real_data()
print("Part 1:", find_all_trails(data, set))
print("Part 2:", find_all_trails(data, UniversalSet))
