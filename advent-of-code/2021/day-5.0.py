inp = open("input.txt", "r")
inputs = inp.readlines()


def formate_input(line):
    x1y1, x2y2 = line.strip().split("->")
    x1, y1 = [int(val) for val in x1y1.strip().split(",")]
    x2, y2 = [int(val) for val in x2y2.strip().split(",")]
    return x1, y1, x2, y2


inputs = [formate_input(line) for line in inputs]


MAX_SIZE = 0


def mark_grid(grid, value=[0, 0, 0, 0]):
    if value[0] == value[2]:
        s, e = value[1], value[3]
        if value[1] > value[3]:
            s, e = value[3], value[1]
        for y in range(s, e + 1):
            grid[value[0]][y] += 1

    elif value[1] == value[3]:
        s, e = value[0], value[2]
        if value[0] > value[2]:
            s, e = value[2], value[0]
        for x in range(s, e + 1):
            grid[x][value[1]] += 1


def first(inputs):
    global MAX_SIZE

    filter_data = []
    for value in inputs:
        if value[0] == value[2] or value[1] == value[3]:
            MAX_SIZE = max(MAX_SIZE, value[0], value[1], value[2], value[3])
            filter_data.append(value)
    MAX_SIZE += 1

    grid = [[0] * MAX_SIZE for y in range(MAX_SIZE)]
    for value in filter_data:
        mark_grid(grid, value)
    ans = 0
    for x in range(MAX_SIZE):
        for y in range(MAX_SIZE):
            if grid[x][y] > 1:
                ans += 1
    return ans


print(first(inputs))
