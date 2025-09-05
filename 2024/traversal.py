from itertools import product

for j in range(1, 5):
    print(f"{j}:")
    lst = sorted(product(range(10), repeat=j), reverse=True, key=sum)
    for e in lst:
        print(*map(lambda i: 9-i, e))
    print()
