from more_itertools import with_iter
from itertools import chain

names = dict(
    zip(
        ("one", "two", "three", "four", "five", "six", "seven", "eight", "nine"),
        map(str, range(1, 10)),
    )
)


def findnum(part: int):
    def impl(line: str) -> int:
        candidates_it = names.values if part == 1 else names.items
        candidates = tuple(chain.from_iterable(candidates_it()))

        def make_digit(idx, off):
            maybe_digit = line[idx : idx + off]
            return maybe_digit if maybe_digit.isdigit() else names[maybe_digit]

        return int(
            make_digit(
                *min(
                    filter(
                        lambda t: t[0] >= 0,
                        map(
                            lambda name: (line.find(name), len(name)),
                            candidates,
                        ),
                    )
                )
            )
            + make_digit(
                *max(
                    filter(
                        lambda t: t[0] >= 0,
                        map(
                            lambda name: (line.rfind(name), len(name)),
                            candidates,
                        ),
                    )
                )
            )
        )

    return impl


print(sum(map(findnum(part=1), with_iter(open("./day1.txt")))))
print(sum(map(findnum(part=2), with_iter(open("./day1.txt")))))
