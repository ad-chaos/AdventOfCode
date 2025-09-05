class Compose:
    """A Composable function object

    Allows you to compose functions using the `@` operator

        @Compose
        def add(a, b): return a+b

        @Compose
        def neg(a): return -b

        negadd = neg @ add
    """
    def __init__(self, func) -> None:
        self.func = func

    def __matmul__(self, other):
        self.func = lambda *args, f=self.func, g=other.func, **kwargs: f(
            g(*args, **kwargs)
        )
        return self

    def __call__(self, *args, **kwargs):
        return self.func(*args, **kwargs)


def crange(*nums):
    """A Circular Range Iterator

    The following should print the same thing

        from itertools import cycle
        from more_itertools import first

        print(*map(first, zip(cycle(range(5)), range(9))))
        print(*crange(5, 9))
    """
    start = stop = times = 0
    step = 1
    match len(nums):
        case 1:
            times = stop = nums
        case 2:
            stop, times = nums
        case 3:
            start, stop, times = nums
        case 4:
            start, stop, times, step = nums
        case _:
            raise TypeError("Need atleast one argument bruh")

    yield start
    while times := times - 1:
        start += step
        yield start % stop
