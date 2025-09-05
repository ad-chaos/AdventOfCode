def test_end(end, src_map):
    ret = None
    for idx, (rsrc_start, rsrc_end) in enumerate(reversed(src_map), 1):
        if end >= rsrc_end or end >= rsrc_start:
            ret = -idx
            break
    return ret

print(test_end(7, [(1, 3), (8, 9), (10, 11)]), "==", -3)
print(test_end(1, [(1, 3), (8, 9), (10, 11)]), "==", -3)
print(test_end(10, [(1, 3), (8, 9), (10, 11)]), "==", -1)
print(test_end(5, [(1, 3), (8, 9), (10, 11)]), "==", -3)
print(test_end(10, [(1, 3), (8, 9), (11, 13)]), "==", -2)
print(test_end(15, [(1, 3), (8, 9), (11, 13)]), "==", -1)
print(test_end(70, [(0, 7), (7, 11), (11, 53), (53, 61)]), "==", -1)
