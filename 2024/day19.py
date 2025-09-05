from pathlib import Path
from functools import cache


def parsed(strings):
    part = strings.index("")
    avail = strings[:part][0].split(", ")
    need = strings[part + 1 :]
    return set(avail), need


def test_data():
    return parsed(
        """r, wr, b, g, bwu, rb, gb, br

brwrr
bggr
gbbr
rrbgbr
ubwu
bwurrg
brgr
bbrgwb""".split("\n")
    )


def real_data():
    return parsed(Path("input19.txt").read_text().strip().split("\n"))


avail, need = real_data()


@cache
def check_possible(cand):
    if not len(cand):
        return 1

    count = 0
    for i in range(len(cand)):
        possible = check_possible(cand[i + 1 :])
        if cand[: i + 1] in avail and possible:
            count += possible

    return count


allways = list(map(check_possible, need))
print("Part 1:", sum(map(bool, allways)))
print("Part 2:", sum(allways))
