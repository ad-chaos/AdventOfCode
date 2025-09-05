from itertools import cycle
from math import lcm

directions = ""
network: dict[str, tuple[str, str]] = {}


def parse_line(line: str) -> tuple[str, tuple[str, str]]:
    frm, to = line.rstrip().split(" = ")
    L, R = to[1:-1].split(", ")
    return (frm, (L, R))


def visualise(engine: str):
    graph = "graph {"  # }
    for node in interested:
        L, R = network[node]
        graph += node + " -- " + L + "; "
        graph += node + " -- " + R + "; "
    graph += "}"
    import subprocess

    subprocess.check_output(
        [engine, "-Tsvg", "-o", f"route-{engine}.svg"], input=graph, text=True
    )


with open("./day8.txt") as f:
    directions = next(f).rstrip()
    next(f)
    network = dict(map(parse_line, f))


current = "AAA"
steps = 0
interested: list[str] = ["AAA"]
for dir in cycle(map(lambda d: (0, 1)[d == "R"], directions)):
    current = network[current][dir]
    interested.append(current)
    steps += 1
    if current == "ZZZ":
        break
print(steps)


current_nodes = list(filter(lambda n: n.endswith("A"), network))
all_steps: list[int] = []
for node in current_nodes:
    current = node
    all_steps.append(0)
    for dir in cycle(map(lambda d: (0, 1)[d == "R"], directions)):
        current = network[current][dir]
        all_steps[-1] += 1
        if current.endswith("Z"):
            break

print(lcm(*all_steps))
