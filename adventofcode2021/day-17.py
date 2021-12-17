with open("input.txt", "r") as inp:
    lines = inp.readlines()

(X1, X2), (Y1, Y2) = [
    (int(pos) for pos in each.split("=")[-1].split(".."))
    for each in lines[0].strip().split(", ")
]


def is_valid(x, y):
    return x <= X2 and y >= Y2


def find_y_ans(x_inc, y_inc):
    x_axix, y_axix = 0, 0
    max_y = y_axix
    while x_axix < X2 and y_axix > Y1:
        x_axix += x_inc
        y_axix += y_inc
        max_y = max(max_y, y_axix)
        if X1 <= x_axix <= X2 and Y1 <= y_axix <= Y2:
            return max_y
        if x_inc > 0:
            x_inc -= 1
        y_inc -= 1
    return -1


def find_ans():
    global X1, X2, Y1, Y2
    ans = 0
    unique_velocity = set()
    for x in range(0, X2 + 1):
        for y in range(Y1, X2 + 1):
            temp = find_y_ans(x, y)
            if temp != -1:
                unique_velocity.add((x, y))
                ans = max(ans, temp)
    return ans, len(unique_velocity)


print(find_ans())
