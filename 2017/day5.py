with open("input5.txt") as f:
    instrs = [int(i.rstrip()) for i in f]

curr_idx = 0
steps = 0
bounds = len(instrs)
while -bounds<=curr_idx<bounds:
    steps += 1
    instr = instrs[curr_idx]
    instrs[curr_idx] += (instr>=3 and -1) or 1
    curr_idx += instr

print(steps)
