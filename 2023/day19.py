from itertools import takewhile
from operator import truth
import inspect


class Part:
    def __init__(self, part: str):
        for p in part[1:-1].split(","):
            attr, eq, val = p.partition("=")
            setattr(self, attr, int(val))

    def __repr__(self):
        return f"Part(x={self.x} m={self.m} a={self.a} s={self.s})"

    def sum(self):
        return self.x + self.m + self.a + self.s


class Machine:
    def __init__(self, workflow: list[str]) -> None:
        self.machine = {}
        self.state = ""
        self.part: Part | None = None
        for flow in workflow:
            npos = flow.find("{")  # }
            name = flow[:npos]
            instrs = flow[npos:][1:-1]
            findder = []
            for instr in instrs.split(","):
                maybe_cond, sep, next_flow = instr.partition(":")
                if sep:
                    attr = maybe_cond[0]
                    comparator = maybe_cond[1]
                    value = int(maybe_cond[2:])
                    match comparator:
                        case ">":
                            findder.append(
                                lambda part,
                                value=value,
                                attr=attr,
                                nf=next_flow: getattr(part, attr) > value and nf
                            )
                        case "<":
                            findder.append(
                                lambda part,
                                value=value,
                                attr=attr,
                                nf=next_flow: getattr(part, attr) < value and nf
                            )
                        case _:
                            assert False, f"You didn't handle {maybe_cond}"
                else:
                    findder.append(lambda *_, ret=maybe_cond: ret)
            self.machine[name] = findder

    def feed(self, part: Part):
        self.part = part
        return self

    def run(self):
        if self.part is None:
            raise ValueError("No part given to run on")

        self.state = "in"
        while self.state not in "AR":
            for instr in self.machine[self.state]:
                if ns := instr(self.part):
                    self.state = ns
                    break

        return self

    def part_sum(self):
        return self.part.sum() if self.state == "A" else 0


with open("./day19.txt") as f:
    itf = map(str.rstrip, iter(f))
    machine = Machine([t for t in takewhile(truth, itf)])
    parts = [Part(t) for t in takewhile(truth, itf)]

    print(sum(map(Machine.part_sum, map(Machine.run, map(machine.feed, parts)))))

    # Part 2 requires specialised traversal, which I'll learn afterwards :)
