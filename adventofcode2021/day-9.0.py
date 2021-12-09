inp = open("input.txt", "r")
inputs = inp.readlines()


inputs = [num.strip() for num in inputs]

ROW, COL = 0, 0

R = [-1, 0, 1, 0]
C = [0, 1, 0, -1]


def check(inputs, i, j, point):
    if i < 0 or j < 0 or i >= ROW or j >= COL:
        return True
    if inputs[i][j] > point:
        return True
    return False


def find_ans(inputs):
    global ROW, COL
    ROW, COL = len(inputs), len(inputs[0])

    ans = 0
    for i in range(ROW):
        for j in range(COL):
            point = inputs[i][j]
            count = 0
            for k in range(4):
                if check(inputs, i + R[k], j + C[k], point):
                    count += 1
            if count == 4:
                ans += 1 + int(point)
                # print(point)
    return ans


print(find_ans(inputs))
