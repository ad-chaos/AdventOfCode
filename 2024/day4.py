import numpy as np
from numpy.lib.stride_tricks import sliding_window_view
import numpy.ma as ma


def part1(input):
    xmas = np.array([list(b"XMAS")])

    def window_with(shape):
        return sliding_window_view(input, shape)

    def conv_reduce(of: np.ndarray) -> int:
        return (of == xmas).all(axis=-1).sum() + (of == np.flip(xmas)).all(
            axis=-1
        ).sum()

    rows = window_with(xmas.shape)
    cols = window_with(xmas.T.shape)
    diags = window_with((xmas.T @ xmas).shape)
    mdiags = diags.diagonal(axis1=-2, axis2=-1)
    adiags = np.flip(diags, -1).diagonal(axis1=-2, axis2=-1)

    return (
        conv_reduce(rows)
        + conv_reduce(np.moveaxis(cols, 2, 3))
        + conv_reduce(mdiags)
        + conv_reduce(adiags)
    )


def part2(input):
    kernel = [
        list(b"M.S"),
        list(b".A."),
        list(b"M.S"),
    ]

    x_mas = ma.masked_equal(
        np.array(kernel),
        ord("."),
    )

    parts = sliding_window_view(input, (3, 3))

    def conv_reduce(kernel: np.ndarray) -> int:
        return (parts == kernel).all(axis=(2, 3)).sum()

    return (
        conv_reduce(x_mas)
        + conv_reduce(x_mas.T)
        + conv_reduce(np.rot90(x_mas))
        + conv_reduce(np.fliplr(x_mas))
    )


search = np.array(list(map(lambda line: list(line.encode()), open("input4.txt"))))

print("Part 1:", part1(search))
print("Part 2:", part2(search))
