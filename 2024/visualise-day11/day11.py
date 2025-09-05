from functools import cache


def stone_split(n, blinks):
    @cache
    def splitter(n, m):
        if m >= blinks:
            return 0

        if n == 0:
            return splitter(1, m + 1)

        sn = str(n)
        if len(sn) % 2 == 0:
            a, b = int(sn[: len(sn) // 2]), int(sn[len(sn) // 2 :])
            return 1 + splitter(a, m + 1) + splitter(b, m + 1)

        return splitter(2024 * n, m + 1)

    return 1 + splitter(n, 0)


data = [27, 10647, 103, 9, 0, 5524, 4594227, 902936]
print("Part 1:", sum(map(lambda n: stone_split(n, 25), data)))
print("Part 2:", sum(map(lambda n: stone_split(n, 75), data)))
