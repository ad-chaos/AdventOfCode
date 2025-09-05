with open("./input4_test.txt") as f:
    fin_sum = 0
    for line in f.readlines():
        letters, checksum = line.rstrip().split("[")
        num_start = letters.rfind("-")
        filtered_string = "".join(sorted(letters[:num_start].replace("-", "")))
        count_dict = {}
        unique_str = set(filtered_string)
        for str in unique_str:
            count_dict[str] = filtered_string.count(str)

        print(filtered_string)
        print(sorted(count_dict, key=lambda iter: count_dict[iter], reverse=True))
