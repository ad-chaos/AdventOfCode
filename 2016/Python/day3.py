# part 1
with open("./input3.txt") as f:
    possible = [False, False, False]
    num_tri = 0
    for line1 in f.readlines():
        line1 = line1.rstrip().split(" ")
        perimeter = sum(map(int, line1))
        for i in range(3):
            if 2 * int(line1[i]) < perimeter:
                possible[i] = True

        if all(possible):
            num_tri += 1
        possible = [False, False, False]

print(num_tri)

# part 2
with open("./input3.txt") as f:
    possible = [False, False, False]
    vertices = [line.rstrip().split(" ") for line in f.readlines()]
    num_tri = 0
    i = 0
    while i < len(vertices):
        line1 = vertices[i]
        line2 = vertices[i + 1]
        line3 = vertices[i + 2]
        for v_all in zip(line1, line2, line3):
            perimeter = sum(map(int, v_all))
            for j in range(3):
                if 2 * int(v_all[j]) < perimeter:
                    possible[j] = True

            if all(possible):
                num_tri += 1
            possible = [False, False, False]

        i += 3

print(num_tri)
