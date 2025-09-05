from itertools import product
trees = []
visible_coords = set()
with open("./input8.txt") as f:
    while tree_line := f.readline().rstrip():
        trees.append(list(map(int, tree_line)))

side_len = len(trees)


def update_visible(trees, mirror=False, flip=False):
    global visible_coords
    maybe_rev = lambda x: x
    if mirror:
        maybe_rev = reversed

    for i in range(side_len):
        curr_max = -1
        for j in maybe_rev(range(side_len)):
            ii, jj = i, j
            if flip:
                ii, jj = j, i

            if curr_max < trees[ii][jj]:
                curr_max = trees[ii][jj]
                visible_coords.add((ii, jj))


# Right to Left
update_visible(trees)

# Left to Right
update_visible(trees, mirror=True)

# Up to down
update_visible(trees, flip=True)
#
# Down to Up
update_visible(trees, mirror=True, flip=True)

for row in range(side_len):
    for column in range(side_len):
        if (row, column) in visible_coords:
            print(end="\033[93m" + str(trees[0][0]) + "\033[0m")
        else:
            print(end=str(trees[row][column]))
    print()


print(len(visible_coords))

scenic_score = 0
for row, column in product(range(side_len), repeat=2):
    L = R = U = D = 0

    try:
        curr_element = trees[row][column + 1]
        for i in range(column + 2, side_len):
            if trees[row][i] >= curr_element and trees[row][i] <= trees[row][column]:
                L += 1
                curr_element = trees[row][i]
                continue
            break
    except:
        pass

    try:
        assert column>0
        curr_element = trees[row][column - 1]
        for i in reversed(range(0, column - 1)):
            if trees[row][i] >= curr_element and trees[row][i] <= trees[row][column]:
                R += 1
                curr_element = trees[row][i]
                continue
            break
    except:
        pass

    try:
        curr_element = trees[row + 1][column]
        for i in range(row + 2, side_len):
            if (
                trees[i][column] >= curr_element
                and trees[i][column] <= trees[row][column]
            ):
                D += 1
                curr_element = trees[i][column]
                continue
            break
    except:
        pass

    try:
        assert row>0
        curr_element = trees[row - 1][column]
        for i in reversed(range(0,row-1)):
            if (
                trees[i][column] >= curr_element
                and trees[i][column] <= trees[row][column]
            ):
                U += 1
                curr_element = trees[i][column]
                continue
            break
    except:
        pass

    scenic_score = max(scenic_score, L * R * U * D)
print(scenic_score)
