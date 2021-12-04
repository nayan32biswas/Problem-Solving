inp = open("input.txt", "r")
inputs = inp.readlines()

inputs = [data.strip() for data in inputs]


def get_int_list(string, dilema=" "):
    return [int(x) for x in string.split(dilema) if x.isdigit()]


numbers = get_int_list(inputs[0], ",")

state = [[]]

for i in range(2, len(inputs)):
    if len(state[-1]) < 5 and len(inputs[i]) > 0:
        state[-1].append(get_int_list(inputs[i], " "))
    else:
        state.append([])


def mark_state(state, val, cache):
    x, y, z, direction = 0, 0, 0, None
    for i in range(0, len(state)):
        for j in range(0, len(state[i])):
            for k in range(0, len(state[i][j])):
                # print(i, j, state[i][j])
                if state[i][j][k] == val:
                    if state[i][j][k] == -1:
                        continue
                    cache[i]["row"][j] += 1
                    cache[i]["col"][k] += 1
                    state[i][j][k] = -1
                    if cache[i]["row"][j] == 5:
                        x, y, z, direction = i, j, k, "row"
                    if cache[i]["col"][k] == 5:
                        x, y, z, direction = i, j, k, "col"
    return x, y, z, direction


def get_unmarked_sum(state):
    sum = 0
    for i in range(0, len(state)):
        for j in range(0, len(state[i])):
            if state[i][j] != -1:
                sum += state[i][j]
    return sum


def first(state, numbers):
    cache = []
    for i in range(0, len(state)):
        cache.append({"row": [0] * 5, "col": [0] * 5})

    for val in numbers:
        i, j, k, direction = mark_state(state, val, cache)
        if direction is not None:
            return get_unmarked_sum(state[i]) * val
    return 0


print(first(state, numbers))
