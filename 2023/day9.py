from operator import add
from typing import Iterator
from functools import reduce

import numpy as np

with open("./day9.txt") as f:

    def add_tups(acc: tuple[int, int], t: tuple[int, int]) -> tuple[int, int]:
        return tuple(map(add, acc, t))

    def extrapolate(seq: Iterator[int]) -> tuple[int, int]:
        iseq = np.array(list(seq))
        first_last: list[np.array[np.int64]] = [iseq[[0, -1]]]

        while np.any(iseq := np.diff(iseq)):
            first_last.append(iseq[[0, -1]])

        before, after = zip(*first_last)
        return np.sum(after), np.frompyfunc(int.__rsub__, 2, 1).reduce(np.flip(before))

    print(
        *reduce(
            add_tups,
            map(extrapolate, map(lambda seq: map(int, seq), map(str.split, f))),
        )
    )
