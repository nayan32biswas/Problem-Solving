inp = open("input.txt", "r")
lines = inp.readlines()
inputs = [line.strip() for line in lines]


def solution_one():
    state = {}
    path = []
    length, idx = len(inputs), 1
    while idx < length:
        line = inputs[idx]
        if line == "$ ls":
            idx += 1
            file_sum = 0
            while idx < length and inputs[idx][0] != "$":
                line = inputs[idx]
                a, _ = line.split(" ")
                if a.isdigit():
                    file_sum += int(a)
                idx += 1
            idx -= 1
            not_mutable_path = tuple(path)
            if not_mutable_path not in state:
                state[not_mutable_path] = file_sum
        elif line == "$ cd ..":
            path.pop()
        else:
            _, _, d = line.split(" ")
            path.append(d)
        idx += 1

    second_state = {}
    for key in state.keys():
        if state[key] <= 100000:
            second_state[key] = state[key]

    ans = 0
    for path in second_state.keys():
        total_sum = second_state[path]
        for child_path in second_state.keys():
            if len(path) >= len(child_path):
                """Child path length should be getter then parent path"""
                continue
            is_prefix = True
            for i in range(len(path)):
                if path[i] != child_path[i]:
                    is_prefix = False
                    break
            if is_prefix:
                total_sum += second_state[child_path]
        # print(path, total_sum)
        if total_sum <= 100000:
            ans += total_sum
    return ans


print(f"Solution 1: {solution_one()}")
# print(f"Solution 2: {solution_tow()}")
