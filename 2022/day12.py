import os
from time import sleep

def disp(t):
    os.system("clear")
    for i, line in enumerate(grid):
        for j, char in enumerate(line):
            if char=="S":
                print(end="S ")
                continue
            if char=="E":
                print(end="E ")
                continue
            if (i,j) in visited:
                print(end="\033[91m\033[1m" + "██" + "\033[0m")
            else:
                print(end="██")
        print()
    print()
    sleep(t)

def dfs(grid: list[list[str]], pos: tuple[int, int]):
    global steps
    global visited
    # debug
    disp(0.0625)

    row, column = pos
    if (grid[row][column] == "E"):
        return True

    for dy, dx in ((0, 1), (0, -1), (1, 0), (-1, 0)):
        if 0 <= (i:=row+dx) < len(grid) and 0 <= (j:=column+dy) < len(grid[0]):
            if (i,j) in visited:
                continue

            if grid[row][column] == "S" or abs(ord(grid[i][j]) - ord(grid[row][column])) in (
                1,
                0,
            ):
                steps += 1
                visited.add((i, j))
                if dfs(grid, (i, j)):
                    print(steps)
                steps -= 1
                visited.remove((i, j))

    disp(0.03125)

with open("./test.txt") as f:
    grid = []
    i = j = 0
    S_pos = (0, 0)
    while line := f.readline().rstrip():
        grid.append([])
        j = 0
        for char in line:
            if char == "S":
                S_pos = (i, j)
            grid[-1].append(char)
            j += 1
        i += 1


steps = 0
visited = set()
disp(1)
dfs(grid, S_pos)
