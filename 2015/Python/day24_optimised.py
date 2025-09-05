from itertools import combinations
from functools import reduce
import operator

numbers = [
    1,
    3,
    5,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    41,
    43,
    47,
    53,
    59,
    61,
    67,
    71,
    73,
    79,
    83,
    89,
    97,
    101,
    103,
    107,
    109,
    113,
]
total_third = int(sum(numbers) / 3)
quantum_entangle = -1
num_gifts = -1


def sum_using(target, array: list[int], memoise={}):
    if target in memoise:
        return memoise[target]
    if target == 0:
        return []
    if target < 0:
        return None

    shortest = None
    for number in array:
        array.remove(number)
        decomposition = sum_using(target - number, array[:])
        if decomposition is not None:
            if shortest is None or len(decomposition) < len(shortest):
                shortest = [*decomposition, number]

    memoise[target] = shortest
    return shortest


min_gifts = sum_using(total_third, numbers[:])
min_gifts = len(min_gifts) if min_gifts is not None else 0
for combi in combinations(numbers, min_gifts):
    if sum(combi) == total_third:
        if quantum_entangle == -1:
            quantum_entangle = reduce(operator.mul, combi, 1)
        else:
            quantum_entangle = min(quantum_entangle, reduce(operator.mul, combi, 1))

print(quantum_entangle)
