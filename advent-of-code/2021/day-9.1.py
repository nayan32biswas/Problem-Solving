inp = open("input.txt", "r")
lines = inp.readlines()


inputs = [list(line.strip()) for line in lines]

ROW, COL = 0, 0

R = [-1, 0, 1, 0]
C = [0, 1, 0, -1]


def check(inputs, i, j):
    if i < 0 or j < 0 or i >= ROW or j >= COL:
        return False
    if inputs[i][j] == "9":
        return False
    return True


# Flood fill
def flood_fill(inputs, i, j):
    inputs[i][j] = "9"
    count = 1
    for k in range(4):
        if check(inputs, i + R[k], j + C[k]):
            count += flood_fill(inputs, i + R[k], j + C[k])
    return count


def find_ans(inputs):
    global ROW, COL
    ROW, COL = len(inputs), len(inputs[0])

    basins = []
    for i in range(ROW):
        for j in range(COL):
            if inputs[i][j] == "9":
                continue
            basins.append(flood_fill(inputs, i, j))
    basins.sort()
    ans = 1
    for n in basins[-3:]:
        ans *= n
    return ans


print(find_ans(inputs))
