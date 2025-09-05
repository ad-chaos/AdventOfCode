with open("input1.txt", "r") as f:
    parens = f.read().strip("\n")

floor = 0

for i, paren in enumerate(parens):
    floor += -2 * (ord(paren) - 40.5)

    if floor == -1:
        # part1
        print(i)
# part2
print(floor)
