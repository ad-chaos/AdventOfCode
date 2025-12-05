from pathlib import Path

grid = Path("input4.txt").read_text()
parsed = list(map(list, grid.split()))
x, y = len(parsed), len(parsed[0])


def get_neighs(i, j):
    neighs = 0
    for dx in (-1, 0, 1):
        for dy in (-1, 0, 1):
            nx, ny = i + dx, j + dy
            if 0 <= nx < x and 0 <= ny < y:
                neighs += parsed[nx][ny] == "@"
    return neighs


def mark_rolls(remove):
    marked = []

    for i, j in remove:
        parsed[i][j] = "."

    for i, row in enumerate(parsed):
        for j, spot in enumerate(row):
            if spot == "@" and get_neighs(i, j) <= 4:
                marked.append((i, j))

    return marked


remove = mark_rolls([])
ans = len(remove)

print(ans)
while len(remove):
    remove = mark_rolls(remove)
    ans += len(remove)
print(ans)
