import re
from pathlib import Path


# np.linalg.solve has some very annoying numerical precision errors
def solve(a1, b1, c1, a2, b2, c2):
    n1 = c2 * b1 - c1 * b2
    n2 = a2 * c1 - a1 * c2
    d = a2 * b1 - a1 * b2

    x, y = 0, 0

    if d:
        x, y = n1 // d, n2 // d

    if x > 0 and x * d == n1 and y > 0 and y * d == n2:
        return x, y
    return 0, 0


def cost(sol):
    x, y = sol
    return 3 * x + y


def test_data():
    return """Button A: X+94, Y+34
Button B: X+22, Y+67
Prize: X=8400, Y=5400

Button A: X+26, Y+66
Button B: X+67, Y+21
Prize: X=12748, Y=12176

Button A: X+17, Y+86
Button B: X+84, Y+37
Prize: X=7870, Y=6450

Button A: X+69, Y+23
Button B: X+27, Y+71
Prize: X=18641, Y=10279""".split("\n\n")


def real_data():
    return Path("input13.txt").read_text().split("\n\n")


p1, p2 = 0, 0
for behavior in real_data():
    a1, a2, b1, b2, c1, c2 = map(int, re.findall(r"\d+", behavior, re.MULTILINE))
    p1 += cost(solve(a1, b1, c1, a2, b2, c2))
    p2 += cost(solve(a1, b1, 10000000000000 + c1, a2, b2, 10000000000000 + c2))
print("Part 1:", p1)
print("Part 2:", p2)
