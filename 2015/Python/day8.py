# Part 1
# by u/oragut
with open("./input8.txt") as f:
    print(sum(len(s[:-1]) - len(eval(s)) for s in f))

#Part 2
# by u/orangut
with open("./input8.txt") as f:
    print(sum(2+s.count('\\')+s.count('"') for s in f))
