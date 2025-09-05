def check_palindrome(a: str) -> bool:
    i = 3
    while i < len(a):
        if a[i - 3] != a[i - 2] and a[i - 3 : i + 1] == a[i - 3 : i + 1][::-1]:
            return True

        i += 1
    return False


with open("./input7.txt") as f:
    supported = 0
    ipv7s = [line.rstrip().replace("[", "]").split("]") for line in f.readlines()]
    for ipv7 in ipv7s:
        not_abba_in_bracket = True
        abba_outside = False
        for i, chars in enumerate(ipv7):
            if i % 2:
                not_abba_in_bracket = not_abba_in_bracket and (
                    not check_palindrome(chars)
                )
            else:
                abba_outside = abba_outside or check_palindrome(chars)

        condition_met = not_abba_in_bracket and abba_outside
        if condition_met:
            supported += 1

print(f"Total TLS supported IPs are: {supported}")
