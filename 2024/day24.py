from pathlib import Path
from operator import and_, or_, xor

data, conns = Path("input24.txt").read_text().strip().split("\n\n")
operate = {"AND": and_, "OR": or_, "XOR": xor}
rop = {and_: "AND", or_: "OR", xor: "XOR"}

sdata = {var: int(val) for var, val in map(lambda e: e.split(": "), data.split("\n"))}
sconns = {}
graph = {}

for iconn in conns.strip().split("\n"):
    fop, out = iconn.split(" -> ")
    a1, op, a2 = fop.split()

    graph[frozenset((a1, op, a2))] = out

    sconns[out] = (a1, a2, operate[op])
    if sdata.get(a1, None) is None:
        sdata[a1] = None
    if sdata.get(a2, None) is None:
        sdata[a2] = None
    sdata[out] = None


def set_nums(a, b):
    for k in sdata:
        sdata[k] = None
    for j in range(45):
        sdata["x" + str(j).zfill(2)] = (a & (1 << j)) >> j
        sdata["y" + str(j).zfill(2)] = (b & (1 << j)) >> j


def evaluate():
    while None in sdata.values():
        for out, (a1, a2, operate) in sconns.items():
            if sdata[a1] is not None and sdata[a2] is not None:
                sdata[out] = operate(sdata[a1], sdata[a2])


def show_adder():
    print("digraph {")  # }
    for out, (a1, a2, op) in sorted(sconns.items()):
        aop = rop[op]
        if out.startswith("z"):
            print(f'_{out} [label="{out}"];')
            print(f"{out}->_{out}")
        print(f'{out} [label="{aop}({out})"];')
        print(f"{a1}->{out};")
        print(f"{a2}->{out};")
    print("}")
    exit(0)

# show_adder()

def get_num():
    fin = ""
    for k, v in sorted(sdata.items(), reverse=True):
        if k.startswith("z"):
            fin += str(v)
    return int(fin, 2)


evaluate()
print("Part 1:", get_num())


def test_with(a, b):
    set_nums(a, b)
    evaluate()
    return a + b, get_num()


incorrect = set()


def structure(i, c):
    # S = a ⊕ b ⊕ c
    # C = a•b + c•(a⊕b)

    a = "x" + str(i).zfill(2)
    b = "y" + str(i).zfill(2)
    z = "z" + str(i).zfill(2)

    if i == 45:
        if c != z:
            pass
        return

    SUM = None
    CARRY = None

    axb = graph.get(frozenset((a, "XOR", b)))
    if axb is None:
        print(f"{a}⊕{b}")
        return

    SUM = graph.get(frozenset((axb, "XOR", c)))
    if SUM is None:
        print(f"{a}⊕{b}⊕{c}")
        return

    if SUM != z:
        print(f"{a}⊕{b}⊕{c} = {SUM}")
        return

    axb_c = graph.get(frozenset((axb, "AND", c)))
    if axb_c is None:
        print(f"{c}•({a}⊕{b})")
        return

    a_b = graph.get(frozenset((a, "AND", b)))
    if a_b is None:
        print(f"{a}•{b}")
        return

    CARRY = graph.get(frozenset((axb_c, "OR", a_b)))
    if CARRY is None:
        print(f"{a}⊕{b}•{c} + {a}•{b}")
        return

    structure(i + 1, CARRY)


# structure(1, graph[frozenset(("x00", "AND", "y00"))])
# create a graph
# run this, inspect the problem site
# fix and repeat
print("Part 2: dgr,dtv,fgc,mtj,vvm,z12,z29,z37") # just manually did it
