from timeit import timeit
from random import randint


class Test:
    def __init__(self, size):
        self.g = [
            [0 for _ in range(size + randint(10, 40))]
            for _ in range(size + randint(10, 40))
        ]
        self.sx = len(self.g)
        self.sy = len(self.g[0])

    def in_bounds_len(self, x, y):
        return 0 <= x < self.g.__len__() and 0 <= y < self.g[0].__len__()

    def in_bounds_attr(self, x, y):
        return 0 <= x < self.sx and 0 <= y < self.sy


SIZE = 4000
t = Test(SIZE)
x, y = randint(0, SIZE), randint(0, SIZE)
g = [[0 for _ in range(SIZE + randint(10, 40))] for _ in range(SIZE + randint(10, 40))]
sx, sy = len(g), len(g[0])

print(timeit("t.in_bounds_len(x,y)", globals={"t": t, "x": x, "y": y}))
print(timeit("t.in_bounds_attr(x,y)", globals={"t": t, "x": x, "y": y}))
print(
    timeit(
        "0 <= x < g.__len__() and 0 <= y < g[0].__len__()",
        globals={"g": g, "x": x, "y": y},
    )
)
print(
    timeit("0 <= x < sx and 0 <= y < sy", globals={"sx": sx, "sy": sy, "x": x, "y": y})
)
