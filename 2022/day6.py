from more_itertools import sliding_window
from itertools import takewhile
from functools import reduce
from operator import add

print(
    reduce(
        add,
        map(
            bool,
            takewhile(
                lambda packet: len(set(packet)) != len(packet),
                sliding_window(open("./input6.txt").read(), w:=4),
            ),
        ),
        w)
)
