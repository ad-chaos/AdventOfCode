from tqdm import trange
from itertools import combinations
from functools import reduce
import operator

numbers = [ 1, 3, 5, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, ]
total_third = int(sum(numbers) / 3)
quantum_entangle = -1
num_gifts = -1

#for i in trange(len(numbers)):
#    for combi in combinations(numbers, i):
#        if sum(combi) == total_third:
#            if num_gifts == -1:
#                num_gifts = len(combi)
#            else:
#                num_gifts = min(num_gifts, len(combi))
#
#print(num_gifts)
for combi in combinations(numbers, 6):
    if sum(combi) == total_third:
        if quantum_entangle == -1:
            quantum_entangle = reduce(operator.mul, combi, 1)
        else:
            quantum_entangle = min(quantum_entangle, reduce(operator.mul, combi, 1))

print(quantum_entangle)
