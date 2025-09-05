from itertools import starmap
import numpy as np

with open("./day4.txt") as f:
    # part 1
    lines = [line[line.find(":") + 1 :] for line in f]
    matches = np.array(
        list(
            starmap(
                lambda wins, haves: len(set(wins) & set(haves)),
                map(lambda line: map(str.split, line.split(" | ")), lines),
            )
        ),
    )

    print(np.sum(1 << matches >> 1))

    # part 2
    cards = np.ones(len(matches), dtype=int)
    for i, dups in enumerate(matches, 1):
        cards[i : i + dups] += cards[i - 1]

    print(np.sum(cards))
