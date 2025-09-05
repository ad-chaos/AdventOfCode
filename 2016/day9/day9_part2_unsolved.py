import sys
def reduce_markers(a: str) -> str:
    reduced_string = a
    while "(" in reduced_string:
        i = 0
        while i < len(reduced_string):
            c = reduced_string[i]
            marker = ""
            if c == "(":
                position = i
                i += 1
                while (c := reduced_string[i]) != ")":
                    marker += c
                    i += 1
                i += 1

                try:
                    read, repeat = marker.split("x")
                except ValueError:
                    print(reduced_string)
                    sys.exit(1)

                read = int(read)
                repeat = int(repeat)

                repeater = reduced_string[i : i + read]
                reduced_string = reduced_string.replace(
                    reduced_string[position : i + read], repeat * repeater, 1
                )
                i = i + read - 1
            else:
                i += 1

    return reduced_string


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
            read = int(read)
            repeat = int(repeat)

            repeater = c + f.read(read - 1)
            total_lenght += repeat*len(reduce_markers(repeater))
        else:
            total_lenght += 1

print(total_lenght)
