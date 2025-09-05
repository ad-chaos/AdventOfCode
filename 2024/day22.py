from itertools import islice
from collections import deque, defaultdict
from pathlib import Path
from tqdm import tqdm


def real_data():
    return list(map(int, Path("input22.txt").read_text().splitlines()))


def test_data():
    return [1, 2, 3, 2024]


def mix(a, b):
    return a ^ b


def prune(num):
    return num % 16777216


class Prng:
    def __init__(self, seed):
        self.curr = None
        self.next = seed
        self.window = deque(maxlen=4)
        self.diffmap = {}

    def __iter__(self):
        return self

    def __next__(self):
        self.curr = self.next

        n1 = prune(mix(self.curr << 6, self.curr))
        n2 = prune(mix(n1 >> 5, n1))
        n3 = prune(mix(n2 << 11, n2))

        self.next = n3

        self.window.append(self.next % 10 - self.curr % 10)
        if len(self.window) == 4:
            diff = tuple(self.window)
            if diff not in self.diffmap:
                self.diffmap[diff] = self.next % 10

        return self.curr


seeds = real_data()

prngs = list(map(Prng, seeds))
print(
    "Part 1:",
    sum(map(lambda prng: next(islice(prng, 2000, None)), tqdm(prngs, leave=False))),
)

seqs = defaultdict(int)
for prng in tqdm(prngs, leave=False):
    next(prng)
    for diff, v in prng.diffmap.items():
        seqs[diff] += v
print("Part 2:", max(seqs.values()))
