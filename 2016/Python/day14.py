from hashlib import md5
from bisect import insort

salt = "abc"
num = 39

req = 1

array3 = []
array5 = []
curr_ans = 0


def check_repeat(a, rep):
    for i in range(len(a) - rep + 1):
        not_rep = ord(a[i]) * rep
        for char in a[i : i + rep]:
            not_rep -= ord(char) * (ord(char) == ord(a[i]))
        if not_rep == 0:
            return (True, a[i])

    return (False, "lol")


while req<=64:
    for _ in range(1000):
        hashed = md5(f"{salt}{num}".encode()).hexdigest()
        is_triple, letter = check_repeat(hashed, 3)
        if is_triple:
            insort(array3, (num, letter))
        is_quintuple, letter = check_repeat(hashed, 5)
        if is_quintuple:
            insort(array5, (num, letter))
        num += 1

    for num3, letter3 in array3:
        for num5, letter5 in array5:
            if 0 < num5 - num3 <= 1000 and letter3 == letter5:
                curr_ans = num3
                array3.remove(num3)
                print(f"{num3} is a key because {num5} and both have letter {letter3} key_no:{req}")
                req += 1


print(curr_ans)
