from __future__ import annotations

from string import ascii_letters
from more_itertools import batched
from operator import add, and_, or_
from functools import reduce


class BitSet:
    def __init__(self, string, bitrep: int = 0) -> None:
        self.bitrep = bitrep or reduce(
            or_, map(lambda c: 1 << ascii_letters.index(c), string)
        )

    def __and__(self, other: BitSet) -> BitSet:
        return BitSet("", self.bitrep & other.bitrep)

    def bit_len(self) -> int:
        return self.bitrep.bit_length()


with open("input3.txt") as test:

    input = test.read().splitlines()

    # Part 1
    print(
        reduce(
            add,
            map(
                lambda line: (
                    BitSet(line[: len(line) // 2]) & BitSet(line[len(line) // 2 :])
                ).bit_len(),
                input,
            ),
        )
    )

    # Part 2
    print(
        reduce(
            add,
            map(
                lambda lines: reduce(and_, map(BitSet, lines)).bit_len(),
                batched(input, 3),
            ),
        )
    )
