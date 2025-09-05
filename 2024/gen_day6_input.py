with open("day6-input.h", "w") as header, open("input6.txt") as data:
    header.write("#define INPUT {")  # }
    header.write(','.join(map(lambda row : "{" + ",".join(map(lambda c: f"'{c}'", row.strip())) + "}", data)))
    header.write("}\n")
