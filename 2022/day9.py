from more_itertools import sliding_window
from math import copysign
from typing import Self


class Vector:
    def __init__(
        self, direction: tuple[int, int], prev: tuple[int, int] | None = None
    ) -> None:
        self.dx, self.dy = direction
        self.prev = prev

    def __add__(self, other: Self):
        return Vector((self.dx + other.dx, self.dy + other.dy))

    def __iadd__(self, other: Self):
        self.dx += other.dx
        self.dy += other.dy
        return self

    def __sub__(self, other: Self):
        return Vector((self.dx - other.dx, self.dy - other.dy))

    def __isub__(self, other: Self):
        self.dx -= other.dx
        self.dy -= other.dy
        return self

    def __mul__(self, fac: int):
        return Vector((self.dx * fac, self.dy * fac))

    def __imul__(self, fac: int):
        self.dx *= fac
        self.dy *= fac
        return self

    def __ior__(self, other: Self):
        self.dx += copysign(1, self.dx - other.dx)
        self.dy += copysign(1, self.dy - other.dy)
        return self

    def __str__(self) -> str:
        return "({0} {1})".format(self.dx, self.dy)

    def not_reachable_from(self, other: Self) -> bool:
        return abs(self.dy - other.dy) >= 2 or abs(self.dx - other.dx) >= 2


dir_map = {
    "R": Vector((1, 0)),
    "L": Vector((-1, 0)),
    "U": Vector((0, 1)),
    "D": Vector((0, -1)),
}

with open("./test.txt") as f:
    visited = {(0, 0)}
    deltas = []
    for line in f:
        dir, fac = line.split()
        deltas.extend(dir_map[dir] for _ in range(int(fac)))

    knots = [Vector((0, 0)) for _ in range(10)]
    for delta in deltas:
        for idx, (h_id, t_id) in enumerate(sliding_window(range(10), 2)):
            H, T = knots[h_id], knots[t_id]
            if idx == 0:
                H += delta
            if T.not_reachable_from(H):
                T |= H
                if idx == 8:
                    visited.add((T.dx, T.dy))

for x, y in visited:
    print(x, y, sep="\t")
