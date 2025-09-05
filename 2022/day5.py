from more_itertools import batched

with open("input5.txt") as f:
    containers: list[list[str]] = [[] for _ in range(9)]
    for i, line in enumerate(f):
        for stack, (_, crate, _, _) in enumerate(batched(line, 4)):
            if crate != " ":
                containers[stack].append(crate)
        if i >= 7:
            break
    f.readline()  # Numbers
    f.readline()  # Empty Line

    instrs = map(lambda line: map(int, line.rstrip().split()[1::2]), f.readlines())
    for amt, src, dest in instrs:
        # add a [::-1] for part 1 xD
        containers[dest-1] = containers[src-1][:amt] + containers[dest-1]
        del containers[src-1][:amt]

    print("".join(crates[0] for crates in containers))
