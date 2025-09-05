import numpy as np
from pathlib import Path


grids = [
    np.array([[{"#": False, ".": True}[c] for c in line] for line in g.split()])
    for g in Path("./day13.txt").read_text().split("\n\n")
]


def column_reflection(grid: np.ndarray[bool], *, smudge: bool = False) -> int:
    columns = grid.shape[1]
    for r in range(2, columns, 2):
        hr = r // 2
        if np.invert(grid[:, :hr] == grid[:, hr:r][:, ::-1]).sum() == smudge:
            return hr
        if np.invert(grid[:, -hr:] == grid[:, -r:-hr][:, ::-1]).sum() == smudge:
            return columns - hr

    return 0


def row_reflection(grid: np.ndarray[bool], *, smudge: bool = False) -> int:
    return column_reflection(grid.T, smudge=smudge)


part1 = 0
part2 = 0
for grid in grids:
    part1 += column_reflection(grid)
    part1 += 100 * row_reflection(grid)

    part2 += column_reflection(grid, smudge=True)
    part2 += 100 * row_reflection(grid, smudge=True)

print(part1, part2)
