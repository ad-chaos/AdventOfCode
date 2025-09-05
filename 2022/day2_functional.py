from functools import reduce
from operator import add

r = [3,6,0]
o = lambda t: map(ord, t)
A, X, Y = o("AXY")

def d(comp,me):
    print(r[me-comp-X+A]+me-X+1)
    return (r[me-comp-X+A]+me-X+1, r[me-Y]+1+(comp+me-Y-A)%3)

print(
    *reduce(
        lambda x, y: map(add, x, d(*y)),
        map(lambda x: o(x.split()),
            open("input2.txt").read().splitlines()
        ),
        (0,0)
    )
)
