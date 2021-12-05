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
    else:
        x_direction, y_direction = 1, 1
        if value[0] > value[2]:
            x_direction = -1
        if value[1] > value[3]:
            y_direction = -1
        inc = 0
        while True:
            x, y = value[0] + inc * x_direction, value[1] + inc * y_direction
            grid[x][y] += 1
            if x == value[2] and y == value[3]:
                break
            inc += 1


def calculateable_line(value=[0, 0, 0, 0]):
    d1, d2 = abs(value[0] - value[2]), abs(value[1] - value[3])
    if d1 == 0 or d2 == 0:
        return True  # 180 digree
    if d1 == d2:
        return True  # 45 digree
    return False


def second(inputs):
    global MAX_SIZE

    filter_data = []
    for value in inputs:
        if calculateable_line(value):
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


print(second(inputs))
