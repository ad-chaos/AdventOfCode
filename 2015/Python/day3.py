import numpy as np

with open("input3.txt", "r") as f:
    direcs = f.read().strip("\n")
# part 1
vec_map = {
    "^": np.array([0, 1]),
    "<": np.array([-1, 0]),
    ">": np.array([1, 0]),
    "v": np.array([0, -1]),
}

final_vec = np.zeros(2)
all_points = []
for direc in direcs:
    final_vec += vec_map[direc]
    all_points.append(tuple(final_vec))

print(len(set(all_points)))


# part 2
final_vec1 = np.zeros(2)
final_vec2 = np.zeros(2)
all_points = []
for i, direc in enumerate(direcs):
    if not i % 2:
        final_vec1 += vec_map[direc]
        all_points.append(tuple(final_vec1))
    else:
        final_vec2 += vec_map[direc]
        all_points.append(tuple(final_vec2))

print(len(set(all_points)))
