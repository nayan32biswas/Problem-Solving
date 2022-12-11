inp = open("input.txt", "r")
lines = inp.readlines()
inputs = []

for line in lines:
    line = line.strip()
    inputs.append([int(val) for each in line.split(",") for val in each.split("-")])


def solution_one():
    ans = 0
    for line in inputs:
        if (line[0] <= line[2] and line[3] <= line[1]) or (
            line[2] <= line[0] and line[1] <= line[3]
        ):
            ans += 1

    return ans


def solution_two():
    ans = 0
    for line in inputs:
        if line[0] <= line[2] <= line[1] or line[0] <= line[3] <= line[1]:
            ans += 1
        elif line[2] <= line[0] <= line[3] or line[2] <= line[1] <= line[3]:
            ans += 1
    return ans


# print(f"Solution 1: {solution_one()}")
print(f"Solution 2: {solution_two()}")
