with open("./input9.txt") as f:
    total_lenght = 0
    while True:
        marker = ""
        c = f.read(1)
        if c == "\n":
            break
        if c == "(":
            while (c := f.read(1)) != ")":
                marker += c
            c = f.read(1)

            read, repeat = marker.split("x")
            marker = ""
            read = int(read) - 1
            repeat = int(repeat)

            total_lenght += (int(read)+1) * int(repeat)
            repeater = c

            f.read(read)
            #while read:
            #    repeater += f.read(1)
            #    read -= 1

            #while repeat:
            #    print(end=repeater)
            #    repeat -= 1
        else:
            #print(end=c)
            total_lenght += 1

print(total_lenght)
