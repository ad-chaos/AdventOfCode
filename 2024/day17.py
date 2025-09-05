from itertools import batched


class Machine:
    @staticmethod
    def generate(program):
        mch = Machine()
        regs, prg = program.split("\n\n")
        for reg in regs.split("\n"):
            _, ty, val = reg.split()
            match ty:
                case "A:":
                    mch.a = int(val)
                case "B:":
                    mch.b = int(val)
                case "C:":
                    mch.c = int(val)
        mch.instrs = list(map(int, prg.split()[-1].split(",")))
        return mch

    def __init__(self, instrs=[], a=0, b=0, c=0):
        self.ip = 0
        self.a = a
        self.b = b
        self.c = c
        self.stdout = []
        self.instrs = instrs
        self.imap = {
            0: self.adv,
            1: self.bxl,
            2: self.bst,
            3: self.jnz,
            4: self.bxc,
            5: self.out,
            6: self.bdv,
            7: self.cdv,
        }

    def odecode(self, operand):
        match operand:
            case lit if lit in range(4):
                return lit
            case 4:
                return self.a
            case 5:
                return self.b
            case 6:
                return self.c
        assert False

    def adv(self, operand):
        self.a = self.a >> self.odecode(operand)
        self.ip += 2

    def bdv(self, operand):
        self.b = self.a >> self.odecode(operand)
        self.ip += 2

    def cdv(self, operand):
        self.c = self.a >> self.odecode(operand)
        self.ip += 2

    def bxl(self, operand):
        self.b ^= operand
        self.ip += 2

    def bst(self, operand):
        self.b = self.odecode(operand) % 8
        self.ip += 2

    def jnz(self, operand):
        if self.a:
            self.ip = operand
        else:
            self.ip += 2

    def bxc(self, operand):
        self.b ^= self.c
        self.ip += 2

    def out(self, operand):
        self.stdout.append(self.odecode(operand) % 8)
        self.ip += 2

    def output(self):
        return ",".join(map(str, self.stdout))

    def run(self):
        while self.ip + 1 < len(self.instrs):
            op, operand = self.instrs[self.ip : self.ip + 2]
            self.imap[op](int(operand))
        return self

    def once(self):
        while self.ip + 1 < len(self.instrs):
            op, operand = self.instrs[self.ip : self.ip + 2]
            if op == 3:
                return self
            self.imap[op](int(operand))
        return self

    def dry_run(self):
        for op, operand in batched(self.instrs, 2):
            print(self.imap[op].__name__, operand)
        return self

    def reset(self):
        self.a = 0
        self.b = 0
        self.c = 0
        self.ip = 0
        self.stdout.clear()
        return self

    def set_a(self, a):
        self.a = a
        return self

    def is_quine(self):
        return self.instrs == self.stdout


def tests():
    def mprint(*args):
        print(*args, sep=" == ")

    mprint(
        Machine(a=2024, instrs=[0, 1, 5, 4, 3, 0]).run().output(),
        "4,2,5,6,7,7,7,7,3,1,0",
    )
    mprint(Machine(c=9, instrs=[2, 6]).run().b, 1)
    mprint(Machine(a=10, instrs=[5, 0, 5, 1, 5, 4]).run().output(), "0,1,2")
    mprint(Machine(a=2024, instrs=[0, 1, 5, 4, 3, 0]).run().a, 0)
    mprint(Machine(b=29, instrs=[1, 7]).run().b, 26)
    mprint(Machine(b=2024, c=43690, instrs=[4, 0]).run().b, 44354)

    mprint(
        Machine.generate(
            """Register A: 729
Register B: 0
Register C: 0

Program: 0,1,5,4,3,0"""
        )
        .run()
        .output(),
        "4,6,3,5,6,3,5,2,1,0",
    )


mch = Machine.generate(
    """Register A: 63687530
Register B: 0
Register C: 0

Program: 2,4,1,3,7,5,0,3,1,5,4,1,5,5,3,0"""
)


def get_min(a=0, lastn=1):
    mina = None

    for i in range(8):
        output = mch.reset().set_a((a << 3) | i).run().stdout
        if output == mch.instrs[-lastn:]:
            possible = (
                (a << 3) | i
                if output == mch.instrs
                else get_min((a << 3) | i, lastn + 1)
            )
            if possible:
                mina = possible if mina is None else min(possible, mina)

    return mina


print("Part 1:", mch.run().output())
print("Part 2:", get_min())
