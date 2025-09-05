import operator

dir_to_vec = {
    0:lambda count:(0,1*count),
    1:lambda count:(1*count,0),
    2:lambda count:(0,-1*count),
    3:lambda count:(-1*count,0),
}

#dirs = ["R8", "R4", "R4", "R8"]
dirs = [
"L2", "L3", "L3", "L4", "R1", "R2", "L3", "R3", "R3", "L1", "L3", "R2", "R3", "L3", "R4", "R3", "R3", "L1", "L4", "R4", "L2", "R5", "R1", "L5", "R1", "R3", "L5", "R2", "L2", "R2", "R1", "L1", "L3", "L3", "R4", "R5", "R4", "L1", "L189", "L2", "R2", "L5", "R5", "R45", "L3", "R4", "R77", "L1", "R1", "R194", "R2", "L5", "L3", "L2", "L1", "R5", "L3", "L3", "L5", "L5", "L5", "R2", "L1", "L2", "L3", "R2", "R5", "R4", "L2", "R3", "R5", "L2", "L2", "R3", "L3", "L2", "L1", "L3", "R5", "R4", "R3", "R2", "L1", "R2", "L5", "R4", "L5", "L4", "R4", "L2", "R5", "L3", "L2", "R4", "L1", "L2", "R2", "R3", "L2", "L5", "R1", "R1", "R3", "R4", "R1", "R2", "R4", "R5", "L3", "L5", "L3", "L3", "R5", "R4", "R1", "L3", "R1", "L3", "R3", "R3", "R3", "L1", "R3", "R4", "L5", "L3", "L1", "L5", "L4", "R4", "R1", "L4", "R3", "R3", "R5", "R4", "R3", "R3", "L1", "L2", "R1", "L4", "L4", "L3", "L4", "L3", "L5", "R2", "R4", "L2"
]
vector = [0,0]
north = 0
every_point = []
atomic = True

for dir in dirs:
    turn, count = dir[0], dir[1:]
    count = int(count)
    numeric_dir = 1 if turn=='R' else -1
    for i in range(count):
        vector = tuple(map(operator.add, vector, dir_to_vec[(north+numeric_dir)%4](1)))
        if vector in every_point and atomic:
            # part 2
            print(vector)
            print(abs(vector[0])+abs(vector[1]))
            atomic = False
        else:
            every_point.append(vector)
    north = (north+numeric_dir)%4

#part 1
print(vector)
print(abs(vector[0])+abs(vector[1]))
