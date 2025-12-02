from collections import defaultdict
from pathlib import Path

regs = defaultdict(int)

def cval(reg, op, amt):
    amt = int(amt)
    match op:
        case '>':
            return regs[reg] > amt
        case '>=':
            return regs[reg] >= amt
        case '<':
            return regs[reg] < amt
        case '<=':
            return regs[reg] <= amt
        case '==':
            return regs[reg] == amt
        case '!=':
            return regs[reg] != amt

def reval(reg, op, amt):
    amt = int(amt)
    match op:
        case 'inc':
            regs[reg] += amt
        case 'dec':
            regs[reg] -= amt

ans = 0
for line in map(str.split, Path("./input8.txt").read_text().rstrip().splitlines()):
    reg, op, amt, _, creg, cop, camt = line
    if cval(creg, cop, camt):
        reval(reg, op, amt)
        ans = max(*regs.values(), ans)

print(max(regs.values()))
print(ans)
