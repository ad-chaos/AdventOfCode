from pathlib import Path
from operator import add, mul, itemgetter
from functools import reduce
from itertools import groupby

raw_problems = Path("input6.txt").read_text()


def solve(problems):
    ans = 0
    for nums, op in problems:
        match op:
            case "+":
                ans += reduce(add, map(int, nums))
            case "*":
                ans += reduce(mul, map(int, nums))
    return ans


def part1():
    problems = zip(*map(str.split, raw_problems.splitlines()))
    ans = 0
    for *nums, op in problems:
        match op:
            case "+":
                ans += reduce(add, map(int, nums))
            case "*":
                ans += reduce(mul, map(int, nums))
    return ans


def part2():
    *parsed, ops = raw_problems.splitlines()
    transposed = zip(*map(list, parsed))
    concatenated = map(lambda n: "".join(n), transposed)
    problems = zip(
        map(
            itemgetter(1),
            filter(itemgetter(0), groupby(concatenated, lambda n: n != "    ")),
        ),
        ops.split(),
    )

    ans = 0
    for nums, op in problems:
        match op:
            case "+":
                ans += reduce(add, map(int, nums))
            case "*":
                ans += reduce(mul, map(int, nums))
    return ans


print(part1())
print(part2())
