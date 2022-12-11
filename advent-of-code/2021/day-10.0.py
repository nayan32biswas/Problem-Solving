inp = open("input.txt", "r")
lines = inp.readlines()

inputs = [line.strip() for line in lines]

parentheses = {"(": ")", "{": "}", "[": "]", "<": ">"}
value = {")": 3, "]": 57, "}": 1197, ">": 25137}


def check_parentheses(line):
    stack = []
    for char in line:
        if char in parentheses:
            stack.append(char)
        else:
            if len(stack) == 0:
                return "", True
            if parentheses[stack.pop()] != char:
                return char, False
    return "", True


def find_ans(inputs):
    ans = 0
    for line in inputs:
        char, is_valid = check_parentheses(line)
        if is_valid is False:
            ans += value[char]
    return ans


print(find_ans(inputs))
