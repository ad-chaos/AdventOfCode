with open("./input23.txt") as f:
    instructions = [i.rstrip().split(" ") for i in f.readlines()]

a = 1
b = 0
i = 0
reg, ins, offset = "", "", 0
instruction_map = {
    "inc": lambda _, reg, iter: (reg + 1, iter + 1),
    "tpl": lambda _, reg, iter: (3 * reg, iter + 1),
    "hlf": lambda _, reg, iter: (reg / 2, iter + 1),
    "jmp": lambda offset, reg, iter: (reg, offset + iter),
    "jio": lambda offset, reg, iter: (reg, iter + offset if reg == 1 else iter + 1),
    "jie": lambda offset, reg, iter: (reg, iter + 1 if reg % 2 else iter + offset),
}
while i < len(instructions):
    offset = 0
    if instructions[i][0][:2] == "ji":
        ins, reg, offset = instructions[i]
        offset = int(offset)
    elif instructions[i][0][0] == "j":
        ins, offset = instructions[i]
        offset = int(offset)
    else:
        ins, reg = instructions[i]

    if reg == "a":
        a, i = instruction_map[ins](offset, a, i)
    else:
        b, i = instruction_map[ins](offset, b, i)

print(f"{a=}")
print(f"{b=}")
