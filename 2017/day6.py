blocks = [0, 5, 10, 0, 11, 14, 13, 4, 11, 8, 8, 7, 1, 4, 12, 11]


def find_loops(
    blocks: list[int], test_against: tuple[int, ...] | None = None
) -> tuple[int, tuple[int, ...]]:
    seen = set()
    rounds = len(blocks)
    chosen_set = set()
    if test_against is not None:
        chosen_set.add(test_against)
    else:
        chosen_set = seen

    while (curr_state := tuple(blocks)) not in chosen_set:
        seen.add(curr_state)
        start = blocks.index(max(blocks))
        redist = blocks[start]
        blocks[start] = 0
        idx = (start + 1) % rounds
        while redist:
            blocks[idx] += 1
            redist -= 1
            idx += 1
            idx %= rounds

    return len(seen), tuple(blocks)


len_loop_1, state = find_loops(blocks.copy())
print(len_loop_1)

len_loop_2, _ = find_loops(blocks.copy(), test_against=state)
print(len_loop_1 - len_loop_2)
