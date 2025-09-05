from hashlib import md5
import sys

num = 0
go_on = True
while True:
    input = f"bgvyzdsv{num}"
    hash = md5(input.encode()).hexdigest()

    if hash[:6] == "000000": # part-1 5 zeroes and part-2 6 zeroes
        print(num)
        break
    num += 1
