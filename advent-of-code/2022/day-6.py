inp = open("input.txt", "r")
lines = inp.readlines()
line = lines[0].strip()


def solution(length):
    multiple_count = 0
    count_state = [0] * 127
    for i in range(length):
        val = ord(line[i])
        count_state[val] += 1
        if count_state[val] == 2:
            multiple_count += 1
    if multiple_count == 0:
        return length

    for i in range(0, len(line) - length - 2):
        a, b = ord(line[i]), ord(line[i + length])
        count_state[a] -= 1
        if count_state[a] == 1:
            multiple_count -= 1
        count_state[b] += 1
        if count_state[b] == 2:
            multiple_count += 1
        if multiple_count == 0:
            return i + length + 1
    return 0


# print(f"Solution 1: {solution(4)}")
print(f"Solution 2: {solution(14)}")
