from bisect import bisect
from itertools import accumulate, repeat, batched, starmap
from operator import mul
from pathlib import Path
from dataclasses import dataclass
from enum import IntEnum, auto
from tqdm import tqdm


class BlockTy(IntEnum):
    File = auto()
    Free = auto()


@dataclass
class Block:
    id: int
    count: int
    ty: BlockTy

    def __iter__(self):
        return iter((0 if self.ty == BlockTy.Free else self.id, self.count))


def compact_files(string):
    dmap = list(map(int, string))
    compacted = bisect(list(accumulate(dmap)), sum(dmap) - sum(dmap[1::2]))

    compacted_disk, free_disk = (
        dmap[:compacted],
        dmap[compacted:],
    )

    aug_compdisk = [(i >> 1, e) for i, e in enumerate(compacted_disk)]

    aug_freedisk = [(i >> 1, e) for i, e in enumerate(free_disk, start=compacted)][
        compacted % 2 :: 2
    ]

    for two_blocks in batched(aug_compdisk, 2):
        if len(two_blocks) < 2:
            two_blocks = *two_blocks, None
        file_block, free_block = two_blocks
        file_id, file_count = file_block
        yield file_id, file_count

        if free_block is None:
            continue

        _, free_count = free_block
        while free_count:
            fill_id, fill_count = aug_freedisk.pop()
            can_fill = min(fill_count, free_count)
            yield fill_id, can_fill

            free_count -= can_fill

            if fill_count > can_fill:
                aug_freedisk.append((fill_id, fill_count - can_fill))

    yield from aug_freedisk


def compact_blocks(string):
    dmap = list(map(int, string))
    dmap[::2] = starmap(
        lambda id, count: Block(id, count, BlockTy.File), enumerate(dmap[::2])
    )
    dmap[1::2] = map(lambda count: Block(".", count, BlockTy.Free), dmap[1::2])

    if dmap[-1].ty == BlockTy.Free:
        dmap.pop()

    dmap = dmap[::-1]
    for i in tqdm(range(len(dmap)), leave=False):
        if dmap[i].ty == BlockTy.File:
            for j in reversed(range(i, len(dmap))):
                if dmap[j].ty == BlockTy.Free:
                    if dmap[j].count < dmap[i].count:
                        continue

                    if dmap[j].count > dmap[i].count:
                        dmap[j].count -= dmap[i].count
                        dmap[j : j + 1] = [dmap[j], dmap[i]]
                        dmap[i] = Block(".", dmap[i].count, BlockTy.Free)
                    elif dmap[j].count == dmap[i].count:
                        dmap[j], dmap[i] = dmap[i], dmap[j]

                    break

    return reversed(dmap)


def calc_checksum(filesystem):
    i = 0
    chksum = 0
    for id, count in filesystem:
        chksum += sum(map(mul, range(i, count + i), repeat(id)))
        i += count
    return chksum


def test_data():
    return "2333133121414131402"


def real_data():
    return Path("input9.txt").read_text().strip()

from time import time_ns
start = time_ns()
print("Part 1:", calc_checksum(compact_files(real_data())))
print(time_ns() - start)
print("Part 2:", calc_checksum(compact_blocks(real_data())))
