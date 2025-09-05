from math import prod, sqrt, floor

times = [49, 78, 79, 80]
distances = [298, 1185, 1066, 1181]


def num_beats(time, dist):
    return min(2 * floor((sqrt(time * time - 4 * dist)) / 2 - time), 0) % time + 1


print(prod(map(num_beats, times, distances)))
print(num_beats(int("".join(map(str, times))), int("".join(map(str, distances)))))
