inp = open("input.txt", "r")
lines = inp.readlines()

inputs = [[int(num) for num in list(line.strip())] for line in lines]


ROW, COL = len(inputs), len(inputs[0])

R = [-1, -1, 0, 1, 1, 1, 0, -1]
C = [0, 1, 1, 1, 0, -1, -1, -1]


def check_position(i, j):
    if 0 <= i < ROW and 0 <= j < COL and inputs[i][j] < 10:
        return True
    return False


def flash(inputs, i, j):
    for r, c in zip(R, C):
        if check_position(i + r, j + c):
            inputs[i + r][j + c] += 1
            if inputs[i + r][j + c] == 10:
                flash(inputs, i + r, j + c)


def step(inputs):
    for i in range(ROW):
        for j in range(COL):
            inputs[i][j] += 1
            if inputs[i][j] == 10:
                flash(inputs, i, j)
    count = 0
    for i in range(ROW):
        for j in range(COL):
            if inputs[i][j] >= 10:
                inputs[i][j] = 0
                count += 1
    return count


def first(inputs, days):
    ans = 0
    for _ in range(days):
        ans += step(inputs)
    return ans


def second(inputs):
    ans = 0
    while True:
        ans += 1
        if step(inputs) == 100:
            break
    return ans


# print(first(inputs, 100))
print(second(inputs))
