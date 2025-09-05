n = 2024

seen = set()
def test(n):
    if n in seen:
        return

    sn = str(n)
    seen.add(n)

    if n == 0:
        print(0, "->", 1, ";")
        test(1)
    elif len(sn) % 2 == 0:
        a, b = int(sn[: len(sn) // 2]), int(sn[len(sn) // 2 :])
        print(n, "->", a, ";")
        print(n, "->", b, ";")
        test(a)
        test(b)
        seen.add(a)
        seen.add(b)
    else:
        print(n, "->", 2024*n, ";")
        test(2024*n)
        seen.add(2024*n)

print("digraph G {")
print("splines=true;")
print("fontsize=20;")
print("bgcolor=black;")
print("edge [ penwidth=3 ];")
print("node [ penwidth=3 fontsize=25 ];")
test(0)
print("}")
