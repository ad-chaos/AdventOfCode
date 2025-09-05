import operator
from typing import Tuple

with open("./input2.txt") as f:
    inss = [line.rstrip() for line in f.readlines()]

dir_map = {
    "R": (1, 0),
    "L": (-1, 0),
    "U": (0, 1),
    "D": (0, -1),
}

coords_to_num1 = {
    (-1, 1): "1",
    (0, 1): "2",
    (1, 1): "3",
    (-1, 0): "4",
    (0, 0): "5",
    (1, 0): "6",
    (-1, -1): "7",
    (0, -1): "8",
    (1, -1): "9",
}


coords_to_num2 = {
    (-1, 1): "2",
    (0, 1): "3",
    (1, 1): "4",
    (-1, 0): "6",
    (0, 0): "7",
    (1, 0): "8",
    (-1, -1): "A",
    (0, -1): "B",
    (1, -1): "C",
    (0, 2): "1",
    (0, -2): "D",
    (2, 0): "9",
    (-2, 0): "5",
}

pos1 = (0, 0)
pos2 = (-2, 0)
password1 = ""
password2 = ""

def custom_adder1(a, b):
    c = a+b
    if c:
        return c/abs(c)
    else:
        return 0

def custom_adder(prev: Tuple[int, int], vec: Tuple[int, int]):
    new_code = tuple(map(operator.add, prev, vec))
    if abs(new_code[0])+abs(new_code[1]) <= 2:
        return new_code
    else:
        return prev


for ins in inss:
    for char in ins:
        pos1 = tuple(map(custom_adder1, pos1, dir_map[char]))
        pos2 = custom_adder(pos2, dir_map[char])
    password1 += coords_to_num1[pos1]
    password2 += coords_to_num2[pos2]


print(password1)
print(password2)
