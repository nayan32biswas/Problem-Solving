inp = open("input.txt", "r")
lines = inp.readlines()

inputs = [line.strip() for line in lines]

parentheses = {"(": ")", "{": "}", "[": "]", "<": ">"}
value = {"(": 1, "[": 2, "{": 3, "<": 4}


def check_parentheses(line):
    stack = []
    for char in line:
        if char in parentheses:
            stack.append(char)
        else:
            if len(stack) == 0:
                return 0
            if parentheses[stack.pop()] != char:
                return 0
    stack.reverse()
    total = 0
    for char in stack:
        total = (total * 5) + value[char]
    return total


def find_ans(inputs):
    data_list = []
    for line in inputs:
        temp = check_parentheses(line)
        if temp != 0:
            data_list.append(temp)
    data_list.sort()
    return data_list[int(len(data_list) / 2)]


print(find_ans(inputs))
