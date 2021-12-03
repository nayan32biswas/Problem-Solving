inp = open("input.txt", "r")
lines = inp.readlines()


def parse_line(line):
    words = line.split(" ")
    main_bag = words[0] + words[1]
    bag_list = []
    for idx, word in enumerate(words):
        if word.isdigit():
            bag_list.append((int(word), words[idx + 1] + words[idx + 2]))
    return {main_bag: bag_list}


def extract_lines(lines):
    datas = {}
    for line in lines:
        datas.update(parse_line(line))
    return datas


shinygold = "shinygold"


def find_data(datas, bags):
    if len(bags) == 0:
        return 1
    sum = 0
    for bag in bags:
        sum += bag[0] * find_data(datas, datas[bag[1]])
    return sum + 1


datas = extract_lines(lines)
print(find_data(datas, [(1, shinygold)]) - 2)
