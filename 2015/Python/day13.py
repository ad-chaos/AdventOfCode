import itertools

with open("./input13.txt", "r") as f:
    intermediate = [inf.rstrip().split(" ") for inf in f.readlines()]
    info = {(name1, name2) : int(val) for name1,val,name2 in intermediate}

names = ["Alice", "Bob", "Carol", "David", "Eric", "Frank", "George", "Mallory", "I"]

for name in names[:-1]:
    info[(name,"I")]=0;
    info[("I",name)]=0;

max_happiness = 0
total1, total2 = 0, 0
for arrangement in itertools.permutations(names[:-1]):
    arrangement += ("I",)
    for name1,name2 in zip(arrangement,arrangement[1:]+arrangement[:-1]):
        total1 += info[(name1,name2)]
        total2 += info[(name2,name1)]
    max_happiness = max(total1 + total2, max_happiness)
    total1, total2 = 0, 0

print(max_happiness)
