with open("./input21.txt") as f:
    values = {}
    for line in f:
        name, val = line.rstrip().split(": ")
        try:
            values[name] = int(val)
        except ValueError:
            continue

    f.seek(0)
    input = f.read()

for k,v in values:
    input.replace(k, str(v))

for line in input.splitlines():
    for var, expr in line.split(": "):
        pass
