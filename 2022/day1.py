with open("input1.txt") as f:
    curr_max = []
    curr_elf = 0
    for i in f.readlines():
        i = i.rstrip()
        if i:
            curr_elf += int(i)
        else:
            curr_max.append(curr_elf)
            curr_elf = 0

sorted_calories = sorted(curr_max, reverse=True)

print(sorted_calories[0])
print(sum(sorted_calories[:3]))
