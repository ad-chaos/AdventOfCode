balance_map = {
    "(": ")",
    "[": "]",
    "{": "}",
    "<": ">",
}
opening_chars = balance_map.keys()

points_table = {
    ")": 3,
    "]": 57,
    "}": 1197,
    ">": 25137,
}

with open("input10.txt") as f:
    lines = [line.rstrip() for line in f.readlines()]

points = 0
for line in lines:
    stack = []
    expected = ""
    for char in line:
        if char in opening_chars:
            stack.append(char)
        elif char == expected:
            stack.pop()
        else:
            points += points_table[char]
            stack.pop()

        if len(stack):
            expected = balance_map[stack[-1]]
        else:
            expected = ""

print(points)
