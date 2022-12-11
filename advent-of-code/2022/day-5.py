inp = open("input.txt", "r")
lines = inp.readlines()
inputs = []


def parse_input():
    stacks, moves = [], []

    idx = 0
    stack_lines = []
    for _ in lines:
        line = lines[idx]
        idx += 1

        if line == "\n":
            break
        stack_lines.append(line)

    number_line = stack_lines.pop()
    stack_lines.reverse()

    stacks.append([])
    for i in range(len(number_line)):
        if number_line[i].isdigit():
            pos = int(number_line[i])

            stacks.append([])
            for j in range(len(stack_lines)):
                if stack_lines[j][i] == " ":
                    break
                stacks[pos].append(stack_lines[j][i])

    for i in range(idx, len(lines)):
        moves.append([int(val) for val in lines[i].strip().split(" ") if val.isdigit()])
    return stacks, moves


stacks, moves = parse_input()


def solution_one():
    ans = ""
    for move in moves:
        for _ in range(move[0]):
            if len(stacks[move[1]]) > 0:
                stacks[move[2]].append(stacks[move[1]].pop())
        # print(stacks)
    ans = "".join([each[-1] for each in stacks[1:]])
    return ans


def solution_two():
    ans = ""
    for move in moves:
        stacks[move[2]] += stacks[move[1]][-move[0]:]
        for _ in range(move[0]):
            stacks[move[1]].pop()
    ans = "".join([each[-1] for each in stacks[1:]])
    return ans


# print(f"Solution 1: {solution_one()}")
print(f"Solution 2: {solution_two()}")
