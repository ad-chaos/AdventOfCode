from tqdm import tqdm
import operator

N=100
tot = 2

capacity = (2,0,0,0)
durability = (0,5,0,-1)
flavor = (-2,-3,5,0)
texture = (0,0,-1,5)
calories = (3,3,8,8)

all_params = [capacity, durability, flavor, texture, calories]

def partitions(n):
    for i in range(n):
        for j in range(n-i):
            for k in range(n-i-j):
                yield (i,j,k,N-i-j-k)


def score(part):
    score = 1
    for param in all_params[:-1]:
        param_score = sum(map(operator.mul, part, param)) 
        score *= param_score if param_score>0 else 0
    cal_count = sum(map(operator.mul, part, all_params[-1])) 
    return (score,cal_count)

maximum = 0
for i in tqdm(partitions(N)):
    score_params, calories = score(i)
    if calories==500:
        maximum = max(score_params,maximum)

print(maximum)
