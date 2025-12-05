from pathlib import Path

ing = Path("input5.txt").read_text()
rng, ings = ing.split("\n\n")
intervals = sorted(
    map(lambda r: list(map(int, r.split("-"))), rng.split()),
    key=lambda t: t[0],
)

merged = [range(*intervals[0])]
for start, end in intervals:
    prange = merged[-1]
    if prange.stop < start:
        merged.append(range(start, end + 1))
    else:
        merged[-1] = range(prange.start, max(prange.stop, end + 1))

ans = 0
for n in map(int, ings.splitlines()):
    ans += any(map(lambda interval: n in interval, merged))

print(ans)
print(sum(map(len, merged)))
