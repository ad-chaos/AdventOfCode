from pathlib import Path
import re
import numpy as np
import sys
from base64 import standard_b64encode
from itertools import count


# https://sw.kovidgoyal.net/kitty/graphics-protocol/#a-minimal-example
def serialize_gr_command(**cmd):
    payload = cmd.pop("payload", None)
    cmd = ",".join(f"{k}={v}" for k, v in cmd.items())
    ans = []
    w = ans.append
    w(b"\033_G"), w(cmd.encode("ascii"))
    if payload:
        w(b";")
        w(payload)
    w(b"\033\\")
    return b"".join(ans)


def write_chunked(**cmd):
    data = standard_b64encode(cmd.pop("data"))
    while data:
        chunk, data = data[:4096], data[4096:]
        m = 1 if data else 0
        sys.stdout.buffer.write(serialize_gr_command(payload=chunk, m=m, **cmd))
        sys.stdout.flush()
        cmd.clear()
    print()


coords = [
    [int(x) for x in re.findall(r"-?\d+", line)]
    for line in Path("input14.txt").read_text().strip().split("\n")
]

WIDTH = 101
HEIGHT = 103
dim = np.array([WIDTH, HEIGHT])


def get_safety(coords):
    q1, q2, q3, q4 = 0, 0, 0, 0
    for px, py, vx, vy in coords:
        px += 100 * vx
        px %= WIDTH
        py += 100 * vy
        py %= HEIGHT

        mx, my = WIDTH // 2, HEIGHT // 2

        if px < mx and py < my:
            q1 += 1
        elif px < mx and py > my:
            q2 += 1
        elif px > mx and py < my:
            q3 += 1
        elif px > mx and py > my:
            q4 += 1

    return q1 * q2 * q3 * q4


def gen_image(pos):
    image = np.zeros((HEIGHT, WIDTH, 3), dtype=np.uint8)
    rows, cols = np.hsplit(pos, 2)
    image[cols.flatten(), rows.flatten()] = [255, 255, 255]
    return image


def print_image(img):
    zoom = img.repeat(15, axis=1).repeat(15, axis=0)
    v, s, _ = zoom.shape
    write_chunked(a="T", f=24, s=s, v=v, data=zoom.tobytes())


def calculate_entropy(pos):
    rows, cols = np.hsplit(pos, 2)
    vals = np.ravel(np.histogram2d(rows.flatten(), cols.flatten())[0] / pos.size)
    marg = vals[vals > 0]
    return -np.sum(np.multiply(marg, np.log2(marg)))


def simulate():
    pos = np.array([coord[:2] for coord in coords])
    vel = np.array([coord[2:] for coord in coords])

    mentropy = calculate_entropy(pos)
    mi = 0
    for i in range(10_000):
        pos += vel
        pos %= dim
        centropy = calculate_entropy(pos)
        if centropy < mentropy:
            mentropy = centropy
            #print_image(gen_image(pos))
            mi = i
    return mi


print("Part 1:", get_safety(coords))
print("Part 2:", simulate())
