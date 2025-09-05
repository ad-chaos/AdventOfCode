with open("./input12.txt") as f:
    instructions = [i.rstrip().split(" ") for i in f.readlines()]

registers = dict(a=0, b=0, c=1, d=0)
i = 0

def execute_copy(vor, r, it):
    global registers
    if vor.isnumeric():
        registers[r] = int(vor)
    else:
        registers[r] = registers[vor]

    return it+1

def execute_jump(reg, offset, it):
    global registers

    if reg.isnumeric() and int(reg):
        return it+offset
    if registers[reg]:
        return it+offset

    return it+1

instruction_map = {
    "inc": lambda reg: (reg + 1),
    "dec": lambda reg: (reg - 1),
    "cpy": lambda value_or_reg, reg, it: execute_copy(value_or_reg, reg, it),
    "jnz": lambda reg, offset, it: execute_jump(reg, int(offset), it)
}
while i < len(instructions):
    if instructions[i][0][0] in ("j", "c"):
        ins, arg1, arg2 = instructions[i]
        i = instruction_map[ins](arg1, arg2, i)
    else:
        ins, reg = instructions[i]
        registers[reg] = instruction_map[ins](registers[reg])
        i += 1

print(f"{registers}")
