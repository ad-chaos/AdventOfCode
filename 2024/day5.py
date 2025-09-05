from itertools import pairwise, starmap
from collections import defaultdict
from functools import total_ordering

ordering, orders = open("input5.txt").read().split("\n\n")

h = defaultdict(set)
for k, v in map(lambda s: s.split("|"), ordering.split()):
    h[k].add(v)

@total_ordering
class Number:
    def __init__(self, a):
        self.a = a

    def __gt__(self, other):
        return other.a in h[self.a]

    def __eq__(self, other):
        return other.a == self.a


p1, p2 = 0, 0

for order in map(lambda s: s.split(","), orders.split()):
    if all(starmap(lambda a, b: b in h[a], pairwise(order))):
        p1 += int(order[len(order) // 2])
    else:
        tsort = sorted(order, key=Number)
        p2 += int(tsort[len(tsort) // 2])

print("Part 1:", p1)
print("Part 2:", p2)
