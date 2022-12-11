inp = open("input.txt", "r")
lines = inp.readlines()

new_lines = []

for data in lines:
    data = data.split(" ")
    temp = data[0].split("-")
    data[0] = (int(temp[0]), int(temp[1]))
    data[1] = data[1][0]
    data[2] = data[2][:-1]
    new_lines.append(data)


def is_valid(data):
    coun = 0
    for c in data[2]:
        if c == data[1]:
            coun += 1
    if data[0][0] <= coun <= data[0][1]:
        return 1
    return 0


def is_valid_second(data):
    try:
        f, s = data[0][0] - 1, data[0][1] - 1
        if data[1] == data[2][f] and data[1] != data[2][s]:
            return 1
        if data[1] != data[2][f] and data[1] == data[2][s]:
            return 1
    except:
        pass
    return 0


print(sum([is_valid_second(data) for data in new_lines]))