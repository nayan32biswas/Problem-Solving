with open("input.txt", "r") as inp:
    lines = inp.readlines()


dots = []
folds = []
state = []
X, Y = 0, 0


def print_state(state):
    for row in state:
        print(row)


def create_new_state(x, y):
    return [[0 for _ in range(x + 1)] for _ in range(y + 1)]


for line in lines:
    if "," in line:
        x, y = [int(x) for x in line.strip().split(",")]
        dots.append((x, y))
        X, Y = max(X, x), max(Y, y)
    elif "=" in line:
        value = line.strip().split(" ")[-1]
        direction, distance = value.strip().split("=")
        folds.append((direction, int(distance)))

state = create_new_state(X, Y)
for dot in dots:
    state[dot[1]][dot[0]] = 1


def fold_x(state, point):
    global X, Y
    next = max(point - 1, X - point)
    print(X, Y)

    new_state = create_new_state(next, Y)
    for i in range(next + 1):
        y_low, y_hi = point - i, point + i
        for j in range(Y + 1):
            if y_low >= 0 and y_hi <= X:
                new_state[j][y_low] = state[j][y_low]
                if state[j][y_hi] == 1:
                    new_state[j][y_low] = state[j][y_hi]
    X = next
    return new_state


def fold_y(state, point):
    global X, Y
    next = max(point - 1, Y - point)
    new_state = create_new_state(X, next)
    for i in range(next + 1):
        y_low, y_hi = point - i, point + i
        for j in range(X + 1):
            if y_low >= 0 and y_hi <= Y:
                new_state[y_low][j] = state[y_low][j]
                if state[y_hi][j] == 1:
                    new_state[y_low][j] = state[y_hi][j]
    Y = next
    return new_state


def fold_state(state, direction, point):
    if direction == "x":
        state = fold_x(state, point)
    elif direction == "y":
        state = fold_y(state, point)
    return state


def first(state, folds):
    state = fold_state(state, folds[0][0], folds[0][1])
    return sum(sum(val for val in line) for line in state)


def second(state, folds):
    for fold in folds:
        state = fold_state(state, fold[0], fold[1])
    print_state(state)
    return sum(sum(val for val in line) for line in state)


print(first(state, folds))
# print(second(state, folds))
