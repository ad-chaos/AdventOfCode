from more_itertools import all_equal, sliced
from tqdm import tqdm
from math import floor, log10
from pathlib import Path

rgs = Path("input2.txt").read_text()

def palindrome(n, m):
    h = 10**(m // 2)
    return n%h == n//h

def last_m(n, m):
    t = 10**m
    while n:
        yield n%t
        n = n//t

def repeats(n, m):
    for i in range(m//2):
        yield sliced(str(n), i + 1)

def has_repeats(n, m):
    return any(map(all_equal, repeats(n, m)))

parsed = list(map(lambda r: list(map(int, r.split("-"))), rgs.split(",")))

p1 = 0
p2 = 0

for start, end in tqdm(parsed):
    for n in range(start, end+1):
        m = floor(log10(n)) + 1
        if m%2 == 0 and palindrome(n, m):
            p1 += n
        if has_repeats(n, m):
            p2 += n

print(p1, p2)
