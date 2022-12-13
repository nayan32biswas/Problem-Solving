inp = open("input.txt", "r")
lines = inp.readlines()
inputs = [line.strip() for line in lines]
row, col = len(inputs), len(inputs[0])


def is_visible(i, j):
    tree = inputs[i][j]
    pos = 0
    for y in range(j + 1, col):
        if inputs[i][y] >= tree:
            break
        pos = y
    if pos >= col:
        return True

    return False


def solution_one():

    ans = 0

    for i in range(row):
        for j in range(col):
            if is_visible(i, j):
                ans += 1

    return ans


print(f"Solution 1: {solution_one()}")
# print(f"Solution 2: {solution_tow()}")
