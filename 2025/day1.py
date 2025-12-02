from itertools import accumulate, repeat, chain
from functools import partial
from operator import not_
from pathlib import Path

rots = Path("input1.txt").read_text()

trots = """L50
R505
L300
L5
"""

ilen = lambda iter: sum(1 for _ in iter)
mod_acc = partial(accumulate, func=lambda a, b: (a + b) % 100, initial=50)
zeros = partial(filter, not_)
countz = lambda iter: ilen(zeros(mod_acc(iter)))

irots = list(map(int, rots.replace("R", "+").replace("L", "-").split()))

p1 = countz(irots)
p2 = countz(chain.from_iterable(repeat(1 if rot > 0 else -1, abs(rot)) for rot in irots))

print(p1, p2)
