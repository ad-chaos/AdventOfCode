from collections import Counter
from tqdm import trange

with open("./input14.txt") as f:
    instruction_map = {}
    template = f.readline().rstrip()
    f.readline()

    for line in f.readlines():
        pair, replace = line.rstrip().split(" -> ")
        instruction_map[pair] = replace


steps = 40
for _ in trange(steps):
    insertions = []
    for i in range(len(template)-1):
        insertions.append(instruction_map[template[i:i+2]])

    template_copy = ""
    for j in range(len(insertions)):
        template_copy += template[j] + insertions[j]

    template_copy += template[-1]
    template = template_copy

    steps -= 1


letters = Counter(template)
highest = letters.most_common()[0][1]
lowest = letters.most_common()[-1][1]
print(highest-lowest)
