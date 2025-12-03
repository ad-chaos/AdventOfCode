from pathlib import Path
from tqdm import tqdm

banks = Path("input3.txt").read_text()

def increasing(bank):
    return sorted(enumerate(bank), key=lambda t: int(t[1]), reverse=True)

def find_largest(bank, size=12):
    ans = []
    jolt = ""
    def compute(bank):
        nonlocal ans, jolt
        if len(ans) == size:
            jolt = ''.join(ans)
            return True

        for i, n in increasing(bank):
            ans.append(n)
            if compute(bank[i+1:]):
                return True
            ans.pop()
        return False

    compute(bank)
    return int(jolt)

def large_jolt(bank):
    return max(
        (
            int(n1 + n2)
            for i, n1 in enumerate(bank)
            for j, n2 in enumerate(bank)
            if i != j and j > i
        )
    )

banks = banks.split()
print(sum(map(large_jolt, tqdm(banks))))
print(sum(map(find_largest, tqdm(banks))))
