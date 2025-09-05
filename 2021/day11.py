from itertools import product

octopuses = [
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 2, 4, 7, 8, 6, 6, 8, 3, 2, 4, 0],
    [0, 4, 2, 8, 3, 4, 7, 4, 1, 2, 5, 0],
    [0, 1, 6, 6, 3, 4, 6, 3, 3, 7, 4, 0],
    [0, 1, 7, 3, 8, 2, 7, 1, 3, 2, 3, 0],
    [0, 4, 2, 8, 5, 7, 4, 4, 8, 6, 1, 0],
    [0, 3, 5, 5, 1, 3, 1, 1, 5, 1, 5, 0],
    [0, 8, 5, 7, 4, 3, 3, 5, 4, 3, 8, 0],
    [0, 7, 8, 4, 3, 5, 2, 5, 8, 2, 6, 0],
    [0, 1, 3, 6, 6, 2, 3, 7, 5, 7, 7, 0],
    [0, 3, 5, 5, 4, 6, 8, 7, 2, 2, 6, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
]

octopuses_test = [
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 5, 4, 8, 3, 1, 4, 3, 2, 2, 3, 0],
    [0, 2, 7, 4, 5, 8, 5, 4, 7, 1, 1, 0],
    [0, 5, 2, 6, 4, 5, 5, 6, 1, 7, 3, 0],
    [0, 6, 1, 4, 1, 3, 3, 6, 1, 4, 6, 0],
    [0, 6, 3, 5, 7, 3, 8, 5, 4, 7, 8, 0],
    [0, 4, 1, 6, 7, 5, 2, 4, 6, 4, 5, 0],
    [0, 2, 1, 7, 6, 8, 4, 1, 7, 2, 1, 0],
    [0, 6, 8, 8, 2, 8, 8, 1, 1, 3, 4, 0],
    [0, 4, 8, 4, 6, 8, 4, 8, 5, 5, 4, 0],
    [0, 5, 2, 8, 3, 7, 5, 1, 5, 2, 6, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
]


def increment(state: list[list[int]]):
    for x in range(1, 11):
        for y in range(1, 11):
            state[x][y] += 1


def increment_surrounding(state: list[list[int]], x: int, y: int):
    possible_shifts = [0, 1, -1]
    for i, j in product(possible_shifts, repeat=2):
        state[x + i][y + j] += 1 * (state[x + i][y + j] != 0)


def flash(state: list[list[int]]):
    global count
    keep_running = True
    while keep_running:
        keep_running = False
        for x in range(1, 11):
            for y in range(1, 11):
                if state[x][y] > 9:
                    keep_running = True
                    state[x][y] = 0
                    count += 1
                    increment_surrounding(state, x, y)


count = 0
for _ in range(100):
    increment(octopuses)
    flash(octopuses)

print(count)

not_flashed = True
till_now = 100
while not_flashed:
    increment(octopuses)
    flash(octopuses)
    if sum(sum(line) for line in octopuses) == 0:
        not_flashed = False

    till_now += 1

print(till_now)
