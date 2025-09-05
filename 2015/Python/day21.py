from itertools import combinations, product

Weapons = [(8, 4), (10, 5), (25, 6), (40, 7), (74, 8)]
Armour = [
    (0, 0),
    (13, 1),
    (31, 2),
    (53, 3),
    (75, 4),
    (102, 5),
]
RingsAttack = combinations([(0, 0), (0, 0), (25, 1), (50, 2), (100, 3)], 2)
RingsDefend = combinations([(0, 0), (0, 0), (20, 1), (40, 2), (80, 3)], 2)

minimum = -1
maximum = 0
EnemyD = 8
EnemyP = 2
PlayerD = 0
PlayerP = 0
cost = 0

# each tuple has (cost, deal)
for ((weapon), (armour), (ringsa1, ringsa2), (ringsd1, ringsd2)) in product(
    Weapons, Armour, RingsAttack, RingsDefend
):

    PlayerD = tuple(
        map(
            sum,
            zip(
                weapon,
                ringsa1,
                ringsa2,
            ),
        )
    )
    PlayerP = tuple(
        map(
            sum,
            zip(
                armour,
                ringsd1,
                ringsd2,
            ),
        )
    )

    cost = PlayerP[0] + PlayerD[0]
    PlayerP = PlayerP[1]
    PlayerD = PlayerD[1]
    Effective_damage_Doneby_Player = PlayerD - EnemyP
    Effective_damage_Doneby_Enemy = EnemyD - PlayerP

    if Effective_damage_Doneby_Player >= Effective_damage_Doneby_Enemy:
        if minimum == -1:
            minimum = cost
        else:
            minimum = min(minimum, cost)
    else:
        maximum = max(cost, maximum)

print(minimum)
print(maximum)
