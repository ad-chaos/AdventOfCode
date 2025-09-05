from hashlib import md5

start = "ffykfhsq"
# for seed = abc we get 05ace8e3
password = ["" for _ in range(8)]
used = [False for _ in range(8)]

i=0
while not all(password):
    ID = start + str(i)
    hash = md5(ID.encode()).hexdigest()
    if hash[:5]=="00000":
        if ord(hash[5])-48>=0 and ord(hash[5])-48<8:
            if not used[int(hash[5])]:
                password[int(hash[5])] = hash[6]
                used[int(hash[5])] = True

    i += 1

print("".join(password))
