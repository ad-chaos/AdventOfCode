from __future__ import annotations

from collections import defaultdict
from pathlib import Path
from functools import cache

tree = {}
weights = {}
indegs = defaultdict(int)

for l in map(str.split, Path("./input7.txt").read_text().rstrip().splitlines()):
    if len(l) > 2:
        node, weight, _, *rest = l
        weight = int(weight[1:-1])
        rest = list(map(lambda n: n.rstrip(","), rest))
        tree[node] = rest
        weights[node] = weight
        indegs[node] += 0
        for neigh in rest:
            indegs[neigh] += 1
    else:
        node, weight = l
        weight = int(weight[1:-1])
        tree[node] = []
        weights[node] = weight
        indegs[node] += 0

root = ""
for k, v in indegs.items():
    if v == 0:
        root = k
        break


@cache
def get_weight(root):
    ans = weights[root]
    for neigh in tree[root]:
        ans += get_weight(neigh)
    return ans


assert get_weight(root) == sum(weights.values())


def is_balanced(root):
    programs = defaultdict(list)
    for neigh in tree[root]:
        programs[get_weight(neigh)].append(neigh)

    if len(programs) == 2:
        (w1, n1), (w2, n2) = programs.items()
        if len(n1) == 1:
            print(n1[0], weights[n1[0]])
            return weights[n1[0]] + w2 - w1
        else:
            print(n2[0], weights[n2[0]])
            return weights[n2[0]] + w1 - w2
    return None

# print("digraph {")
# for node, children in tree.items():
#     print(node, f'[label="{node} | ({get_weight(node)}, {weights[node]})"];')
#     for child in children:
#         print(node, "->", child, ";")
# print("}")

print(root)
for node, children in tree.items():
    ans = is_balanced(node)
    if ans:
        print(ans)
        print()
