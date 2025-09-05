from collections import Counter
from operator import itemgetter, mul
from itertools import starmap
from more_itertools import with_iter


def ordering(ord_cards: tuple[str, ...], part2: bool = False):
    card_map = dict(zip(ord_cards, reversed(range(len(ord_cards)))))

    def impl(play: tuple[str, int]) -> tuple[int, tuple[int, ...]]:
        hand, _ = play
        c = Counter(hand)
        keys = c.keys()
        counts = c.values()

        tie_break = tuple(map(lambda c: card_map[c], hand))

        # additional logic for part 2
        if part2:
            j_counts = c.get("J")
            others_can_benefit = len(keys) != 1
            if j_counts is not None and others_can_benefit:
                del c["J"]
                key, _ = c.most_common(1)[0]
                c[key] += j_counts

        match len(keys):
            case 1:
                return (6, tie_break)  # five_of_a_kind

            case 2:
                if 4 in counts:
                    return (5, tie_break)  # four_of_a_kind
                return (4, tie_break)  # full house

            case 3:
                if 3 in counts:
                    return (3, tie_break)  # three_of_a_kind
                return (2, tie_break)  # two_pair

            case 4:
                return (1, tie_break)  # one_pair

            case 5:
                return (0, tie_break)  # high_card

        assert False

    return impl


all_plays = sorted(
    starmap(
        lambda hand, bid: (hand, int(bid)),
        map(str.split, with_iter(open("./day7.txt"))),
    ),
    key=ordering(("A", "K", "Q", "J", "T", "9", "8", "7", "6", "5", "4", "3", "2")),
)

print(sum(starmap(mul, enumerate(map(itemgetter(1), all_plays), 1))))

all_plays.sort(
    key=ordering(
        ("A", "K", "Q", "T", "9", "8", "7", "6", "5", "4", "3", "2", "J"), part2=True
    )
)
print(sum(starmap(mul, enumerate(map(itemgetter(1), all_plays), 1))))
