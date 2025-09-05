
balance_map = {
    "(": ")",
    "[": "]",
    "{": "}",
    "<": ">",
}
opening_chars = balance_map.keys()

points_table = {
    ")": 1,
    "]": 2,
    "}": 3,
    ">": 4,
}

with open("input10.txt") as f:
    lines = [line.rstrip() for line in f.readlines()]

#lines = [
#"[({(<(())[]>[[{[]{<()<>>",
#"[(()[<>])]({[<{<<[]>>("  ,
#"(((({<>}<{<{<>}{[]{[]{}" ,
#"{<[[]]>}<{[{[{[]{()[[[]" ,
#"<{([{{}}[<[[[<>{}]]]>[]]",
#]

points = []
for line in lines:
    stack = []
    expected = ""
    for char in line:
        if char in opening_chars:
            stack.append(char)
        elif char == expected:
            stack.pop()
        else:
            break

        if len(stack):
            expected = balance_map[stack[-1]]
    else:
        total = 0
        for char in reversed(stack):
            total *= 5
            total += points_table[balance_map[char]]

        points.append(total)

print(sorted(points)[len(points)//2])
