import re

with open("input7.txt", "r") as f:
    circuit = f.readlines()

monops = {
    'NOT': lambda x : ~x & 0xFFFF,
}

binops = {
    'AND': lambda a,b: a and b,
    'OR': lambda a,b: a or b,
    'LSHIFT': lambda a,b: a << b,
    'RSHIFT': lambda a,b: a >> b
}

machine = {}

for line in circuit:
    line = line.strip()

    m = (
        re.match(r'(\w+) -> (\w+)', line)
        or re.match(r'(\w+) (\w+) (\w+) -> (\w+)', line)
        or re.match(r'(\w+) (\w+) -> (\w+)', line)
    ).groups()

    machine[m[-1]] = m[:-1]

def evaluate(register_or_value):
    try:
        return int(register_or_value)
    except:
        return run(register_or_value)

def run(register, state = {}):
    if not register in state:
        command = machine[register]

        if len(command) == 1:
            value, = command
            state[register] = evaluate(value)

        elif len(command) == 2:
            monop, input = command
            state[register] = monops[monop](evaluate(input))

        elif len(command) == 3:
            input_1, binop, input_2 = command
            state[register] = binops[binop](evaluate(input_1), evaluate(input_2))

    return state[register]


print(run('a'))