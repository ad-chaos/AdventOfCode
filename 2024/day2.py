from more_itertools import is_sorted
from itertools import starmap, pairwise
from operator import sub


def asc_dsc(vec):
    return (is_sorted(vec) or is_sorted(vec, reverse=True)) and all(
        map(lambda n: 1 <= n <= 3, map(abs, starmap(sub, pairwise(vec))))
    )


with open("input2.txt") as f:
    safe = 0
    recs = []
    for line in f:
        rec = list(map(int, line.split()))
        recs.append(rec)
        safe += asc_dsc(rec)
    print("Part 1:", safe)

    asafe = 0
    for rec in recs:
        for i in range(len(rec)):
            c = rec.copy()
            del c[i]
            if asc_dsc(c):
                asafe += 1
                break

    print("Part 2:", asafe)
