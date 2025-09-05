from functools import reduce
from itertools import combinations, starmap
from operator import add, ne, and_
from collections import Counter

with open("input4.txt") as f:
    print(
        reduce(
            add,
            map(
                lambda w: (
                    len(w) == len(set(w))
                    and reduce(and_, starmap(ne, combinations(map(Counter, w), 2)))
                ),
                map(lambda s: s.split(), f.read().splitlines()),
            ),
        )
    )
