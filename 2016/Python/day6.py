with open("./input6.txt") as f:
    maximum = ["", 0]
    fin_msg1 = ""
    fin_msg2 = ""
    alphabets = [chr(i) for i in range(97, 123)]
    messages = [line.rstrip() for line in f.readlines()]
    nth_character = [char_n for char_n in zip(*messages)]
    for i, char in enumerate(nth_character):
        minimum = ['a', nth_character[i].count('a')]
        for letter in alphabets:

            if char.count(letter) > maximum[1]:
                maximum[0] = letter
                maximum[1] = char.count(letter)
            if char.count(letter) < minimum[1]:
                minimum[0] = letter
                minimum[1] = char.count(letter)

        fin_msg1 += maximum[0]
        fin_msg2 += minimum[0]
        maximum = ["", 0]

print(fin_msg1)
print(fin_msg2)
