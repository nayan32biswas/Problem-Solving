inp = open("input.txt", "r")
lines = inp.readlines()


def parse_line(line):
    words = line.split(" ")
    main_bag = words[0] + words[1]
    bag_list = []
    for idx, word in enumerate(words):
        if word.isdigit():
            bag_list.append(words[idx + 1] + words[idx + 2])
    return {main_bag: bag_list}


def extract_lines(lines):
    datas = {}
    for line in lines:
        datas.update(parse_line(line))
    return datas


shinygold = "shinygold"


def is_contain(datas, bags):
    for bag in bags:
        if shinygold in datas[bag]:
            return 1
        elif len(datas[bag]):
            if is_contain(datas, datas[bag]):
                return 1
    return 0


datas = extract_lines(lines)
sum = 0
for bag in datas.keys():
    if len(datas[bag]):
        if shinygold in datas[bag] or is_contain(datas, datas[bag]):
            sum += 1

print(sum)


"""
('lightred', ['brightwhite', 'mutedyellow'])
('darkorange', ['brightwhite', 'mutedyellow'])
('brightwhite', ['shinygold'])
('mutedyellow', ['shinygold', 'fadedblue'])
('shinygold', ['darkolive', 'vibrantplum'])
('darkolive', ['fadedblue', 'dottedblack'])
('vibrantplum', ['fadedblue', 'dottedblack'])
('fadedblue', [])
('dottedblack', [])
"""