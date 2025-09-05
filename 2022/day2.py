# Opponent
# A -> Rock (1)
# B -> Paper (2)
# C -> Scissors (3)
# 
# A-C = 1
# C-B = 1
# B-A = 1
#
# Me
# X -> Rock (1)
# Y -> Paper (2)
# Z -> Scissors (3)

outcomes = [3,6,0]
rps = [1,2,3]
A = ord("A")
X = ord("X")
Y = ord("Y")
fin_score = 0

with open("./input2.txt") as f:
    for line in f.read().splitlines():
        opponent, me = map(ord, line.split())
        fin_score += outcomes[me-opponent-X+A] + rps[me-X]

print(fin_score)



# Opponent
# A -> Rock (1)
# B -> Paper (2)
# C -> Scissors (3)
# 
# A-C = 1
# C-B = 1
# B-A = 1
#
# Me
# X (-1,2) -> Lose (C->A, B->C, A->B)
# Y (0) -> Draw (same as him)
# Z (-2,1) -> Win (C->B, B->A, A->C)
# X and Z are switches

with open("./input2.txt") as f:
    fin_score = 0
    for line in f.read().splitlines():
        he_played, i_needto = map(ord, line.split())
        # print(chr(he_played), chr(i_needto), i_needto-Y, he_played+i_needto-Y-A)
        fin_score += outcomes[i_needto-Y] + rps[(he_played+i_needto-Y-A)%3]
    print(fin_score)
