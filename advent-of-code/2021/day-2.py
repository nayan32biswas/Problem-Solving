inp = open("input.txt", "r")
lines = inp.readlines()

lines = [data.split(" ") for data in lines]


def first(lines):
    data_list = [(data[0], int(data[1])) for data in lines]
    froword, depth = 0, 0
    for val in data_list:
        if val[0] == "forward":
            froword += val[1]
        elif val[0] == "down":
            depth += val[1]
        elif val[0] == "up":
            depth -= val[1]
    return froword * depth


def second(lines):
    data_list = [(data[0], int(data[1])) for data in lines]
    froword, depth, aim = 0, 0, 0
    for val in data_list:
        if val[0] == "forward":
            froword += val[1]
            depth += aim * val[1]
        elif val[0] == "down":
            aim += val[1]
        elif val[0] == "up":
            aim -= val[1]
    return froword * depth


# print(first(lines))
print(second(lines))
