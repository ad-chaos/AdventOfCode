from itertools import groupby
from operator import eq
from tqdm import tqdm

springs = []
with open("./day12.txt") as f:
    for line in f:
        record, damaged = line.split()
        irecord = list(map(lambda c: {"#": 1, ".": 0, "?": 2}[c], record))
        idamage = list(map(int, damaged.split(",")))
        springs.append((irecord, idamage))

print(springs)


def make_header(name, springs):
    with open(name, "w") as out:
        out.write("#define INPUT ")
        out.write(
            repr(springs)
            .replace("[", "{")
            .replace("]", "}")
            .replace("(", "{")
            .replace(")", "}")
        )
        out.write("\n")


def inflate() -> list[tuple[list[int], list[int]]]:
    new_springs: list[tuple[list[int], list[int]]] = []
    for irecord, idamage in springs:
        inflated_irecords = (
            irecord + [2] + irecord + [2] + irecord + [2] + irecord + [2] + irecord
        )
        new_springs.append((inflated_irecords, idamage * 5))
    return new_springs


# make_header("day11-input.h", springs)
# make_header("day11-input2.h", inflate())


def count(iterable):
    c = 0
    for _ in iterable:
        c += 1
    return c


def __ffs(i) -> int:
    return (i & -i).bit_length()


def to_int(i) -> int:
    ret = 0
    for idx, s in enumerate(i):
        ret += s and 1 << idx
    return ret


bs = 0
for irecord, idamage in tqdm(springs):
    bit_pos = to_int([1 if c == 2 else 0 for i, c in enumerate(irecord)])
    irec = to_int([1 if c != 0 else 0 for i, c in enumerate(irecord)])
    bits = bit_pos.bit_count()
    need_damaged = sum(idamage) - sum(irecord) + 2 * bits
    s = 0
    for i in range(1 << bits):
        if need_damaged != i.bit_count():
            continue

        bp_copy = bit_pos
        j = 0
        while ffs := __ffs(bp_copy):
            irec &= ~(1 << (ffs - 1))
            irec |= ((i >> j) & 1) << (ffs - 1)
            bp_copy ^= 1 << (ffs - 1)
            j += 1

        if all(
            map(
                eq,
                idamage,
                (count(g) for k, g in groupby(map(int, bin(irec)[2:][::-1])) if k),
            )
        ):
            s += 1
    bs += s
print(bs)
