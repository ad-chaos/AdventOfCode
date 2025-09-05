pixels = [[0 for _ in range(50)] for _ in range(6)]


def turn_on(y: int, x: int, pixels_array: list[list[int]] = pixels):
    for i in range(x):
        for j in range(y):
            pixels_array[i][j] = 1


def rotate_row(index: int, amount: int, pixels_array: list[list[int]] = pixels):
    pixels_array[index] = pixels_array[index][-amount:] + pixels_array[index][:-amount]


def rotate_column(index:int, amount:int, pixels_array: list[list[int]] = pixels):
    for _ in range(amount):
        for i in range(6):
            pixels_array[i][index], pixels_array[-1][index] = pixels_array[-1][index], pixels_array[i][index]

def print_array():
    for i in pixels:
        for j in i:
            if j:
                print(end="⬜")
            else:
                print(end="⬛")

        print()

with open("./input8.txt") as f:
    for line in f.readlines():
        specifier, arguments = line.split(' ', 1)
        if specifier == "rect":
            y, x = arguments.split('x')
            turn_on(int(y), int(x))
        elif specifier == "rotate":
            axis, index, amount = arguments.split(' ') 
            if axis == "row":
                rotate_row(int(index), int(amount))
            else:
                rotate_column(int(index), int(amount))
print_array()
print(sum(sum(row) for row in pixels))
