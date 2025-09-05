import hashlib
import sys
import re

def get_hash_part1(salt, index):
    m = hashlib.md5()
    m.update(salt.encode("utf-8"))
    m.update(str(index).encode("utf-8"))
    return m.hexdigest()


def find_five_repeats(hashes, ch):
    quintuple = ch * 5

    for h, i in hashes:
        if h.find(quintuple) != -1:
            return (True, i)

    return (False, "")


def solve(salt, get_hash):
    triple = re.compile(r"(.)\1\1")

    hashes = [(get_hash(salt,x), x) for x in range(1001)]

    index = 0
    found = 0

    while True:
        key = hashes[0][1]
        md = triple.search(hashes.pop(0)[0])
        if md:
            five_rep, num = find_five_repeats(hashes, md.group(1))
            if five_rep:
                found += 1
                print(f"{key} is a key because {num} and both have letter {md.group(1)} key no:{found}")
                if found >= 64:
                    break

        index += 1
        hashes.append((get_hash(salt, index + len(hashes)), index + len(hashes)))

    return index


salt = "abc"
solve(salt, get_hash_part1)
