from collections import defaultdict
from pathlib import Path
from itertools import combinations, starmap, repeat
from tqdm import tqdm


def parsed(strings):
    graph = defaultdict(set)
    for k, v in map(lambda conn: conn.split("-"), strings):
        graph[k].add(v)
        graph[v].add(k)
    return graph


def real_data():
    return parsed(Path("input23.txt").read_text().splitlines())


def test_data():
    return parsed(
        """kh-tc
qp-kh
de-cg
ka-co
yn-aq
qp-ub
cg-tb
vc-aq
tb-ka
wh-tc
yn-cg
kh-ub
ta-co
de-co
tc-td
tb-wq
wh-td
ta-ka
td-qp
aq-cg
wq-ub
ub-vc
de-ta
wq-aq
wq-vc
wh-yn
ka-de
kh-ta
co-tc
wh-qp
tb-vc
td-yn""".splitlines()
    )


graph = real_data()
gl = len(graph)


def all_connected(iterable):
    return all(starmap(lambda a, b: a in graph[b] and b in graph[a], iterable))


def is_clique(vertices):
    return all_connected(combinations(vertices, 2))


def is_vert_connected(vertex, vertices):
    return all_connected(zip(vertices, repeat(vertex)))


def count(iterable):
    return sum(map(lambda _: 1, iterable))


def clique_3():
    cliques = []
    for a, b, c in tqdm(combinations(graph, 3), total=gl * (gl - 1) * (gl - 2) / 6, leave=False):
        if is_clique((a, b, c)):
            cliques.append((a, b, c))
    return cliques


def maximal_clique(triangles):
    max_clique = []
    for triangle in tqdm(triangles, leave=False):
        aclique = list(triangle)
        for vert in graph:
            if is_vert_connected(vert, aclique):
                aclique.append(vert)
        if len(aclique) > len(max_clique):
            max_clique = aclique.copy()

    return max_clique


triangles = clique_3()
print("Part 1:", count(filter(lambda vs: any(map(lambda v: v.startswith("t"), vs)), triangles)))
print("Part 2:", ",".join(sorted(maximal_clique(triangles))))
