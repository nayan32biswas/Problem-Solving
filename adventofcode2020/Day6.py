inp = open("input.txt", "r")
lines = inp.readlines()


def ans(lines):
    datas = []
    line = set()
    reset = True
    for each in lines:
        if each == "\n":
            datas.append(len(line))
            line = set()
            reset = True
            continue
        each = each[:-1]
        if reset:
            line = set(each)
        else:
            line = line.intersection(set(each))
        reset = False
    if len(line):
        datas.append(len(line))
    print(datas)
    return sum(datas)


print(ans(lines))