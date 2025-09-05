import re


def rotate(line, n):
    return line[-n:] + line[:-n]


grid = """\
....XXMAS.
.SAMXMS...
...S..A...
..A.A.MS.X
XMASAMX.MM
X.....XA.A
S.S.S.S.SS
.A.A.A.A.A
..M.M.M.MM
.X.X.XMASX"""


def get_count(where):
    a, b = len(re.findall("XMAS", where)), len(re.findall("SAMX", where))
    print(a + b, end=" ")
    return a + b


def get_all_count(where):
    count = 0
    for line in where:
        count += get_count(line)
    print()
    return count


def part1(mat):
    total = 0
    total += get_all_count(mat)
    return total
    total += get_all_count(map("".join, zip(*mat)))
    total += get_all_count(
        map("".join, zip(*(rotate(line, i) for i, line in enumerate(mat))))
    )
    total += get_all_count(
        map("".join, zip(*(rotate(line, i) for i, line in enumerate(mat[::-1]))))
    )

    return total


mat = [line for line in open("input4.txt")]
print(part1(mat))
# print(part2(mat))
