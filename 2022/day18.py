from collections import defaultdict

coords = set()

with open("./input18.txt") as f:
    for line in f:
        coords.add(eval(line))


def reduce(all_faces, coords):
    global delta
    for coord in coords:
        for dir in (-1, 1):
            for pos in (0, 1, 2):

                i, j, k = coord
                delta[pos] = dir
                dx, dy, dz = delta
                new_loc = (i + dx, j + dy, k + dz)

                if new_loc in coords:
                    all_faces -= 1

                delta[pos] = 0
    return all_faces


delta = [0, 0, 0]
possible_air_pockets = defaultdict(int)
all_faces = reduce(6 * len(coords), coords)
print(all_faces)
