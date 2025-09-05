from itertools import product


def check_palindrome_and_append(a: str, lets_keep_track: list[str]):
    i = 2
    while i < len(a):
        if a[i - 2] != a[i - 1] and a[i - 2 : i + 1] == a[i - 2 : i + 1][::-1]:
            lets_keep_track.append(f"{a[i-2:i+1]}")

        i += 1


def invert_string(b):
    return f"{b[1]}{b[0]}{b[1]}"


with open("./input7.txt") as f:
    list_of_candidates = []
    ipv7s = [line.rstrip().replace("[", "]").split("]") for line in f.readlines()]
    for ipv7 in ipv7s:
        ABA = []
        BAB = []
        for i, chars in enumerate(ipv7):
            if i % 2:
                check_palindrome_and_append(chars, BAB)
            else:
                check_palindrome_and_append(chars, ABA)

        list_of_candidates.append([ABA, BAB])


supported_ssl = 0
for IP in list_of_candidates:
    for aba, bab in product(IP[0], IP[1]):
        if aba == invert_string(bab):
            supported_ssl += 1
            break

print(supported_ssl)
