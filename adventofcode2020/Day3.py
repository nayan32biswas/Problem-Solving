inp = open("input.txt", "r")
state = [data[:-1] for data in inp.readlines()]

line_size = len(state[0])
total_line = len(state)


def encounter(move):
    coun = 0
    right = move[0]
    down = move[1]

    while down < total_line:
        right = right % line_size
        # print(right, down, end=", ")
        if state[down][right] == "#":
            coun += 1
        right += move[0]
        down += move[1]
    return coun


move = (
    (1, 1),
    (3, 1),
    (5, 1),
    (7, 1),
    (1, 2),
)

ans = 1
for m in move:
    ans *= encounter(m)
    # print("")
print(ans)