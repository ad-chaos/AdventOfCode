from functools import reduce
from itertools import combinations, starmap
from operator import and_, ne, add
from collections import Counter

with open("input4.txt") as f:

    # for w in map(lambda s: s.split(), f.read().splitlines()):
    #     print(len(w))
    #     print(len(set(w)))
    #     print(reduce(and_,starmap(ne, combinations(map(Counter, w), 2))))

    print(
        reduce(
            add,
            map(
                lambda w: (
                    len(w) == len(set(w)) and reduce(and_,starmap(ne, combinations(map(Counter, w), 2)))
                ),
                map(lambda s: s.split(), f.read().splitlines()),
            ),
        )
    )
