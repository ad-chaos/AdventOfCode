from pathlib import Path
from itertools import product
from functools import reduce
from operator import add, mul
from tqdm import tqdm


def gen_parsed(string):
    return [
        (int(k), tuple(map(int, v.split())))
        for k, v in map(
            lambda line: line.split(": "),
            string.strip().split("\n"),
        )
    ]


def real_data():
    return gen_parsed(Path("input7.txt").read_text())


def test_data():
    return gen_parsed(
        """190: 10 19
3267: 81 40 27
83: 17 5
156: 15 6
7290: 6 8 6 15
161011: 16 10 13
192: 17 8 14
21037: 9 7 18 13
292: 11 6 16 20"""
    )


data = real_data()


def calibration(ops):
    c = 0
    for ans, fac in tqdm(data, leave=False):
        for op in product(ops.keys(), repeat=len(fac) - 1):
            calc = reduce(
                lambda acc, e: ops[e[0]](acc, e[1]),
                zip(op, fac[1:]),
                fac[0],
            )
            if ans == calc:
                c += ans
                break
    return c


print("Part 1:", calibration({"+": add, "*": mul}))
print("Part 2:", calibration({"+": add, "*": mul, "||": lambda a, b: int(str(a) + str(b))}))
