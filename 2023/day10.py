class Pipe:
    def __init__(self, chr: str):
        self.chr = chr
        self.loop = False

    def char(self):
        return self.chr

    def mark_loop(self):
        self.loop = True

    def is_loop(self):
        return self.loop


to_nicer = {
    "|": "┃",
    "-": "━",
    "L": "┗",
    "J": "┛",
    "7": "┓",
    "F": "┏",
    ".": ".",
    "S": "S",
}

pipes = list(
    map(
        lambda line: list(map(lambda c: Pipe(to_nicer[c]), line.rstrip())),
        open("./day10.txt"),
    )
)


def in_bounds(i: int, j: int) -> bool:
    return 0 <= i < len(pipes) and 0 <= j < len(pipes[0])


NORTH = (-1, 0)
SOUTH = (1, 0)
WEST = (0, -1)
EAST = (0, 1)

connectors = {
    "┃": (NORTH, SOUTH),
    "━": (WEST, EAST),
    "┗": (NORTH, EAST),
    "┛": (NORTH, WEST),
    "┓": (WEST, SOUTH),
    "┏": (SOUTH, EAST),
}

# Just get it visually
start = (22, 114)
pipes[22][114].mark_loop()

next_connector = (21, 114)
pipes[21][114].mark_loop()

end_connector = (23, 114)

while next_connector != end_connector:
    x, y = next_connector
    for dx, dy in connectors[pipes[x][y].char()]:
        nx, ny = x + dx, y + dy
        if in_bounds(nx, ny) and not pipes[nx][ny].is_loop():
            pipes[nx][ny].mark_loop()
            next_connector = (nx, ny)
            break

print(sum(map(lambda pipeline: sum(map(Pipe.is_loop, pipeline)), pipes)) // 2)


def should_switch(prev: str, curr: str) -> bool:
    match prev, curr:
        case _, "━":
            return False
        case ("┗", "┓") | ("┏", "┛"):
            return False

    return True


area = 0
for i in range(len(pipes)):
    inside_loop = pipes[i][0].is_loop()
    state = pipes[i][0].char()
    for j in range(1, len(pipes[i])):
        if pipes[i][j].is_loop() and should_switch(state, pipes[i][j].char()):
            inside_loop = not inside_loop

        if inside_loop:
            area += not pipes[i][j].is_loop()

        curr_char = pipes[i][j].char()
        state = curr_char if curr_char in "┗┛┏┓" else state

print(area)
