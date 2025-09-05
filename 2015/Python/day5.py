import re

with open("./input5.txt", "r") as f:
   strings  = f.readlines()

#part 1
good_pat0 = re.compile(r"[aeiou]{1}")
good_pat1 = re.compile(r"(.)\1")
bad_pat0 = re.compile(r"ab|cd|pq|xy")

#part 2
good_pat02 = re.compile(r"(..).*\1")
good_pat12 = re.compile(r"(.).\1")

#part 1
nice = 0
for string in strings:
    result = True if len(good_pat0.findall(string)) >= 3 else False
    result = result and (True if good_pat1.search(string) is not None else False)
    result = result and (False if bad_pat0.search(string) is not None else True)
    if result:
        nice += 1
print(nice)


for string in strings:
    result = True if good_pat02.search(string) is not None else False
    result = result and (True if good_pat12.search(string) is not None else False)
    if result:
        nice += 1
print(nice)
