with open("./input4.txt") as f:
    part_1 = part_2 = 0
    for line in f:
        (start1, end1), (start2, end2) = map(
            lambda point: map(int, point), map(lambda x: x.split("-"), line.rstrip().split(","))
        )

        part_1 += (
            (start1 <= start2)
            and (end1 >= end2)
            or (start1 >= start2)
            and (end1 <= end2)
        )

        part_2 += (
            (start1 <= end2 <= end1)
            or (start1 <= start2 <= end1)
            or (start2 <= end1 <= end2)
            or (start2 <= start1 <= end2)
        )

print(part_1, part_2)
