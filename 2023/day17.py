from itertools import starmap

grid = [
    [2, 4, 1, 3, 4, 3, 2, 3, 1, 1, 3, 2, 3],
    [3, 2, 1, 5, 4, 5, 3, 5, 3, 5, 6, 2, 3],
    [3, 2, 5, 5, 2, 4, 5, 6, 5, 4, 2, 5, 4],
    [3, 4, 4, 6, 5, 8, 5, 8, 4, 5, 4, 5, 2],
    [4, 5, 4, 6, 6, 5, 7, 8, 6, 7, 5, 3, 6],
    [1, 4, 3, 8, 5, 9, 8, 7, 9, 8, 4, 5, 4],
    [4, 4, 5, 7, 8, 7, 6, 9, 8, 7, 7, 6, 6],
    [3, 6, 3, 7, 8, 7, 7, 9, 7, 9, 6, 5, 3],
    [4, 6, 5, 4, 9, 6, 7, 9, 8, 6, 8, 8, 7],
    [4, 5, 6, 4, 6, 7, 9, 9, 8, 6, 4, 5, 3],
    [1, 2, 2, 4, 6, 8, 6, 8, 6, 5, 5, 6, 3],
    [2, 5, 4, 6, 5, 4, 8, 8, 8, 7, 7, 3, 5],
    [4, 3, 2, 2, 6, 7, 4, 6, 5, 5, 5, 3, 3],
]


UP = (-1, 0)
DOWN = (1, 0)
LEFT = (0, -1)
RIGHT = (0, 1)


def right(dir: tuple[int, int]) -> tuple[int, int]:
    return {
        UP: RIGHT,
        DOWN: LEFT,
        LEFT: UP,
        RIGHT: DOWN,
    }[dir]


def left(dir: tuple[int, int]) -> tuple[int, int]:
    return {
        UP: LEFT,
        DOWN: RIGHT,
        LEFT: DOWN,
        RIGHT: UP,
    }[dir]


def in_bounds(x: int, y: int) -> bool:
    return 0 <= x < len(grid) and 0 <= y < len(grid[0])


dest = (len(grid) - 1, len(grid[0]) - 1)  # The destination
minimum = 1 << 61  # The minimum cost
explore_stk: list[tuple[int, int]] = [
    (12, 11)
]  # The stack to get around recursion limits
same_dir = 0  # How many times did we move in the same direction
dir = RIGHT  # What direction I'm moving in
seen = set()  # All the paths that I've seen
path = [(12, 11)]
min_cache: dict[tuple[int, int], tuple[int, list[tuple[int, int]]]] = {}

for i in reversed(range(len(grid))):
    for j in reversed(range(len(grid[0]))):
        explore_stk = [(i, j)]
        x, y = explore_stk.pop()
        for dx, dy in (dir, left(dir), right(dir)):
            nx, ny = x + dx, y + dy

            if in_bounds(nx, ny) and (nx, ny) not in seen:
                seen.add((nx, ny))
                new_min = sum(starmap(lambda x, y: grid[x][y], path[1:])) + grid[nx][ny]
                if new_min < minimum:
                    minimum = new_min
                    path.append((nx, ny))

print(minimum, path)
