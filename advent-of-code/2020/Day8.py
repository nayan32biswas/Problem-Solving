import re

inp = open("input.txt", "r")
lines = inp.readlines()


def extract_line(lines):
    REGEX = "(\S+ )[\+-](\d+)"
    data_list = []
    for line in lines:
        temp = line.split(" ")
        data_list.append([temp[0], int(temp[1])])
    return data_list


def find_ans(data_list):
    status = [0] * int(len(data_list) + 1)
    nop, acc, jmp = "nop", "acc", "jmp"
    pos, ans = 0, 0
    while pos < len(data_list):
        code, value = data_list[pos]
        if status[pos]:
            return 0
        status[pos] = 1
        if code == nop:
            pos += 1
        elif code == acc:
            ans += value
            pos += 1
        else:
            pos += value
        # print(code, value, pos)
    return ans


def main_ans(data_list):
    for i in range(len(data_list) - 1, -1, -1):
        if data_list[i][0] == "jmp":
            data_list[i][0] = "nop"
            ans = find_ans(data_list)
            if ans:
                return ans
            data_list[i][0] = "jmp"

    return 0


data_list = extract_line(lines)

print(main_ans(data_list))
