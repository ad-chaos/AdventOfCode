aunt_sue = {
    "children": 3,
    "cats": 7,
    "samoyeds": 2,
    "pomeranians": 3,
    "akitas": 0,
    "vizslas": 0,
    "goldfish": 5,
    "trees": 3,
    "cars": 2,
    "perfumes": 1,
}

satisfies = []

with open("./input16.txt") as f:
    for line in f.readlines():
        name_properties = line.split(", ")
        for property in name_properties[1:]:
            prop_name, prop_val = property.split(":")
            if aunt_sue[prop_name] == prop_val:
                satisfies.append(name_properties[0])

print(satisfies)
