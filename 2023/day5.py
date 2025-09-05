from typing import Callable, Iterator
from itertools import groupby, starmap, pairwise, chain
from collections import defaultdict
from more_itertools import chunked, last
from operator import itemgetter, add
from functools import reduce
from pprint import pprint


res_map: dict[str, list[tuple[int, int, int]]] = defaultdict(list[tuple[int, int, int]])
seeds: list[int] = []

# {{{ Test Case
test = map(
    lambda line: line + "\n",
    """\
seeds: 79 14 55 13

seed-to-soil map:
50 98 2
52 50 48

soil-to-fertilizer map:
0 15 37
37 52 2
39 0 15

fertilizer-to-water map:
49 53 8
0 11 42
42 0 7
57 7 4

water-to-light map:
88 18 7
18 25 70

light-to-temperature map:
45 77 23
81 45 19
68 64 13

temperature-to-humidity map:
0 69 1
1 0 69

humidity-to-location map:
60 56 37
56 93 4""".split(
        "\n"
    ),
)
# }}}

with open("./day5.txt") as f:
    almanac = map(str.rstrip, test)
    seeds = list(map(int, next(almanac).split()[1:]))
    for _, g in filter(itemgetter(0), groupby(map(str.strip, almanac), key=bool)):
        kind, __ = next(g).split()
        lg = list(g)
        res_map[kind].extend(
            sorted(
                map(
                    lambda parts: tuple(map(int, parts)),  # type: ignore
                    map(str.split, lg),
                ),
                key=itemgetter(1),
            )
        )


def maps_to_entry(kind: str) -> Callable[[int], int]:
    def mapped_entry(src_entry: int) -> int:
        ans = src_entry
        for dest, src, off in res_map[kind]:
            if src <= src_entry <= src + off:
                ans = dest + src_entry - src
        return ans

    return mapped_entry


# mapped_entries: list[int] = seeds
# for kind in res_map:
#    mapped_entries = list(map(maps_to_entry(kind), mapped_entries))
# print(min(mapped_entries))


def maps_to_range(kind: str) -> Callable[[tuple[int, int]], Iterator[tuple[int, int]]]:
    def mapped_range(src_range: tuple[int, int]) -> Iterator[tuple[int, int]]:
        src_map, dest_map = zip(
            *starmap(
                lambda dest, src, off: ((src, src + off), (src - dest)),
                res_map[kind],
            )
        )
        start, end = src_range

        sidx = last(
            (
                idx
                for idx, (src_start, src_end) in enumerate(src_map)
                if src_start <= start or src_end <= start
            ),
            None,
        )

        eidx = next(
            (
                -idx
                for idx, (rsrc_start, rsrc_end) in enumerate(reversed(src_map), 1)
                if end >= rsrc_end or end >= rsrc_start
            ),
            None,
        )

        if sidx is None or eidx is None:
            yield src_range
            return

        ranges = list(chain.from_iterable(src_map[sidx : len(src_map) + eidx + 1]))

        ranges[0] = max(ranges[0], start)
        ranges[-1] = min(ranges[-1], end)

        for is_mapped, (start, end) in enumerate(pairwise(ranges)):
            if is_mapped % 2 == 0:
                off = dest_map[sidx]
                pprint(("(2)", start - off, end - off), underscore_numbers=True)
                yield (start - off, end - off)
                sidx += 1
            else:
                if start - end:
                    pprint(("(3)", start, end), underscore_numbers=True)
                    yield (start, end)

        return

    return mapped_range


print(maps_to_entry("fertilizer-to-water")(57))
print(
    *chain.from_iterable(
        maps_to_range("fertilizer-to-water")(i) for i in [(81, 95), (57, 70)]
    )
)
print(
    *map(
        maps_to_entry("fertilizer-to-water"),
        reduce(
            add,
            starmap(
                lambda start, end: list(range(start, end + 1)), [(81, 95), (57, 70)]
            ),
        ),
    )
)
exit()

mapped_range: list[tuple[int, int]] = list(
    starmap(lambda start, off: (start, start + off), chunked(seeds, 2))
)
# mapped_range = [(81, 95), (57, 70)]
# print(mapped_range)
# mapped_range = list(
#    chain.from_iterable(maps_to_range("soil-to-fertilizer")(i) for i in mapped_range)
# )
# print()
# print(mapped_range)
# exit()
man_mapp_entries = reduce(
    add,
    starmap(lambda start, off: list(range(start, start + off + 1)), chunked(seeds, 2)),
)
print(man_mapp_entries)

for kind in res_map:
    mapped_range = list(
        chain.from_iterable(maps_to_range(kind)(i) for i in mapped_range)
    )
    man_mapp_entries = list(map(maps_to_entry(kind), man_mapp_entries))
    print(kind)
    print(mapped_range)
    print(man_mapp_entries)
    print()

print(mapped_range)
print(man_mapp_entries)
