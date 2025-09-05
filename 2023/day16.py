contraption = [
    ".|...\\....",
    "|.-.\\.....",
    ".....|-...",
    "........|.",
    "..........",
    ".........\\",
    "..../.\\\\..",
    ".-.-/..|..",
    ".|....-|.\\",
    "..//.|....",
]

#  .|...\....
#  |.-.\.....
#  .....|-...
#  ........|.
#  ..........
#  .........\
#  ..../.\\..
#  .-.-/..|..
#  .|....-|.\
#  ..//.|....


def on_boundary(x: int, y: int) -> bool:
    return x == len(contraption) - 1 or y == len(contraption[0]) - 1


UP = (-1, 0)
DOWN = (1, 0)
LEFT = (0, -1)
RIGHT = (0, 1)

rot1 = {
    UP: RIGHT,
    DOWN: LEFT,
    RIGHT: UP,
    LEFT: DOWN,
}

rot2 = {
    UP: LEFT,
    DOWN: RIGHT,
    RIGHT: DOWN,
    LEFT: UP,
}

dir = RIGHT
turtle = (0, 0)


def add(pos: tuple[int, int], dir: tuple[int, int]) -> tuple[int, int]:
    x, y = pos
    dx, dy = dir
    return (x + dx, y + dy)


stk: list[tuple[int, int]] = []

while True:
    x, y = turtle
    match contraption[x][y]:
        case ".":
            turtle = add(turtle, dir)
        case "|":
            if dir == LEFT or dir == RIGHT:
                (UP, DOWN)
                pass
            else:
                turtle = add(turtle, dir)
        case "-":
            if dir == UP or dir == DOWN:
                (LEFT, RIGHT)
                pass
            else:
                turtle = add(turtle, dir)
        case "/":
            dir = rot1[dir]
            turtle = add(turtle, dir)
        case "\\":
            dir = rot2[dir]
            turtle = add(turtle, dir)
