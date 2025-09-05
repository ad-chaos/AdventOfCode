from typing import Callable
from operator import mul
from functools import reduce


class Monkey:
    # The globals used here are monkies and mod_fac
    def __init__(
        self,
        initial: list[int] = [],
        operation: Callable[[int], int] = lambda x: x,
        can_divide: Callable[[int], bool] = lambda _: True,
    ) -> None:
        self.inspection_count = 0
        self.worries = initial
        self.operation = operation
        self.test = can_divide
        self.gives_to = {}

    def inspect(self):
        self.inspection_count += len(self.worries)
        # For part 1 replace %mod_fac with //3
        self.worries = list(map(lambda x: self.operation(x) % mod_fac, self.worries))

    def give(self):
        for idx, worry in map(
            lambda worry: (self.gives_to[self.test(worry)], worry), self.worries
        ):
            monkies[idx].take(worry)
        self.worries.clear()

    def take(self, item):
        self.worries.append(item)

    def __str__(self) -> str:
        return f"""\
worries : {self.worries}
gives_to: {self.gives_to}
"""


monkies = []
divs = []
curr_monkey = 0

with open("./input11.txt") as f:
    for line in f:
        if line.startswith("Monkey"):
            monkies.append(Monkey())
            continue
        line = line.rstrip().lstrip().split(": ")
        match line:
            case ["Starting items", worries]:
                monkies[-1].worries = list(map(int, worries.split(", ")))

            case ["Operation", op]:
                monkies[-1].operation = eval("lambda " + op.replace("new = ", "old : "))

            case ["Test", should_divide]:
                number = int(should_divide.split()[-1])
                monkies[-1].test = lambda x, number=number: (x % number) == 0
                divs.append(number)

            case ["If false", target]:
                monkies[-1].gives_to[False] = int(target[-1])

            case ["If true", target]:
                monkies[-1].gives_to[True] = int(target[-1])

mod_fac = reduce(mul, divs)

for _ in range(10000):
    for i, monkey in enumerate(monkies):
        monkey.inspect()
        monkey.give()

inspections = sorted(list(map(lambda x: x.inspection_count, monkies)), reverse=True)
print(inspections[0] * inspections[1])
