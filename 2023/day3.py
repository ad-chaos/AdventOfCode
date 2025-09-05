from itertools import product, pairwise
from operator import itemgetter
from more_itertools import consecutive_groups, last

engine: list[list[str]] = [[]]

with open("./day3.txt") as fi:
    engine = [[char for char in line.rstrip()] for line in fi]


def in_bounds(i: int, j: int) -> bool:
    return 0 <= i < len(engine) and 0 <= j < len(engine[0])


number_index: set[tuple[str, int, int]] = set()


def lookaround(i: int, j: int):
    symbol = engine[i][j] + str(i) + str(j)
    for di, dj in filter(any, product((0, 1, -1), repeat=2)):
        ni, nj = i + di, j + dj
        add, sub = True, True

        for s in range(4):
            right = nj + s
            if in_bounds(ni, right):
                if add and engine[ni][right].isdigit():
                    number_index.add((symbol, ni, right))
                else:
                    add = False

            left = nj - s
            if in_bounds(ni, left):
                if sub and engine[ni][left].isdigit():
                    number_index.add((symbol, ni, left))
                else:
                    sub = False


def digit_slices(
    possible_num_idx,
) -> list[tuple[tuple[str, int, int], tuple[str, int, int]]]:
    return list(
        map(
            lambda g: (f := next(g), last(g, f)),
            consecutive_groups(
                sorted(possible_num_idx),
                ordering=lambda t: t[1] * len(engine[0]) + t[2],
            ),
        )
    )


def sym_digits(
    digit_slices: list[tuple[tuple[str, int, int], tuple[str, int, int]]]
) -> list[tuple[str, int]]:
    digits: list[tuple[str, int]] = []
    for (sym, lineno, start), (_, __, end) in digit_slices:
        digits.append((sym, int("".join(engine[lineno][start : end + 1]))))

    return digits


for i, j in product(range(len(engine)), range(len(engine[0]))):
    if engine[i][j] != "." and not engine[i][j].isdigit():
        lookaround(i, j)


digits = sym_digits(digit_slices(number_index))

print(sum(map(itemgetter(1), digits)))

sum = 0
for (sym1, g1), (sym2, g2) in pairwise(digits):
    if sym1[0] == "*" and sym1 == sym2:
        sum += g1 * g2
print(sum)
