from collections import defaultdict
from itertools import repeat
from operator import le

games: list[dict[str, list[int]]] = []
with open("./day2.txt") as f:
    for line in f:
        sets = line[line.find(":") + 1 :].strip()
        gmap: dict[str, list[int]] = defaultdict(list)
        for game in sets.split("; "):
            for showing in game.split(", "):
                count, color = showing.split()
                gmap[color].append(int(count))

        games.append(gmap)

actual = {"red": 12, "green": 13, "blue": 14}

sum = 0
for i, condensed_game in enumerate(games, 1):
    possible = True
    for color, outcomes in condensed_game.items():
        possible &= all(map(le, outcomes, repeat(actual[color])))

    if possible:
        sum += i

print(sum)

sum = 0
for i, condensed_game in enumerate(games, 1):
    power = 1
    for color, outcomes in condensed_game.items():
        power *= max(outcomes)
    sum += power

print(sum)
