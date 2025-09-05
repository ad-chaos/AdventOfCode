from functools import reduce
from operator import concat


class Sprite:
    def __init__(self, location: int) -> None:
        self.location = location

    def __getitem__(self, idx: int) -> bool:
        if idx in (self.location - 1, self.location, self.location + 1):
            return True
        return False


x = 1
part_1 = 0
sprite = Sprite(location=1)
data: list[int] = list(
    reduce(
        concat,
        map(
            lambda op: [0, int(op)] if op else [0],
            map(
                lambda s: s.replace("addx", "").replace("noop", "").strip(),
                open("./input10.txt").readlines(),
            ),
        ),
    )
)

for cycle_count, val in enumerate(data):
    print(end=["  ", "██"][sprite[cycle_count % 40]])

    cycle_count += 1

    if cycle_count % 40 == 0:
        print()

    if cycle_count % 40 == 20:
        part_1 += cycle_count * x

    x += val
    sprite.location = x

print(part_1)
