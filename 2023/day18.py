from dataclasses import dataclass
from operator import itemgetter

test = """\
R 6 (#70c710)
D 5 (#0dc571)
L 2 (#5713f0)
D 2 (#d2c081)
R 2 (#59c680)
D 2 (#411b91)
L 5 (#8ceee2)
U 2 (#caa173)
L 1 (#1b58a2)
U 2 (#caa171)
R 2 (#7807d2)
U 3 (#a77fa3)
L 2 (#015232)
U 2 (#7a21e3)""".split("\n")


@dataclass
class Plan:
    dir: str
    count: int
    color: str


full_plan = [
    Plan(dir, int(count), color[1:-1])
    for dir, count, color in map(lambda line: line.rstrip().split(), test)
]

x, y = 0, 0
lagoon = []
for plan in full_plan:
    match plan.dir:
        case "U":
            y += plan.count
        case "D":
            y -= plan.count
        case "L":
            x -= plan.count
        case "R":
            x += plan.count
    lagoon.append((x, y))

lagoon.sort(key=itemgetter(1))
for x, y in lagoon:
    print(x, y, sep="\t")

print(max(lagoon, key=itemgetter(0))[0], min(lagoon, key=itemgetter(1))[1])

print(max(lagoon, key=itemgetter(0))[0], min(lagoon, key=itemgetter(1))[1])
