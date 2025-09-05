from tqdm import tqdm
import json
import numpy as np

with open("./input6.txt", "r") as f:
    instructions = json.load(f)

lights = np.zeros((1000, 1000), dtype=int)

modify = {
    0: lambda state: state - 1 if state else 0,
    1: lambda state: state + 1,
    2: lambda state: state + 2,
}
for instruction in tqdm(instructions):
    doer, x1, y1, x2, y2 = instruction
    if x2 > x1:
        x2, x1 = x1, x2
    if y2 > y1:
        y2, y1 = y1, y2

    for i in range(x2, x1 + 1):
        for j in range(y2, y1 + 1):
            lights[i][j] = modify[doer](lights[i][j])


print(lights.sum())
