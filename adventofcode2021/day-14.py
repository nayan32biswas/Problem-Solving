with open("input.txt", "r") as inp:
    lines = inp.readlines()


input_state = {}
state = {}
ans = {}

for i in range(65, 91):
    ans[chr(i)] = 0

first_line = lines[0].strip()
for i in range(len(first_line)):
    if i + 1 < len(first_line):
        key = f"{first_line[i]}{first_line[i+1]}"
        if key not in state:
            state[key] = 0
        state[key] += 1
    ans[first_line[i]] += 1

for line in lines[2:]:
    a, b = line.split(" -> ")
    input_state[a.strip()] = b.strip()


def find_ans(steps):
    global state, input_state, ans
    for _ in range(steps):
        temp_memory = []
        for key in state:
            if key in input_state:
                temp_memory.append(
                    {"count": state[key], "next_char": input_state[key], "key": key}
                )
        for obj in temp_memory:
            next_char = obj["next_char"]
            key, count = obj["key"], obj["count"]
            left, right = key[0] + next_char, next_char + key[1]

            state[key] -= count

            ans[next_char] += count
            if left == right:
                ans[next_char] += count

            if left not in state:
                state[left] = 0
            if right not in state:
                state[right] = 0

            state[left] += count
            state[right] += count
    MAX, MIN = 0, 1e20
    for key in ans:
        if ans[key] > 0:
            MAX = max(MAX, ans[key])
            MIN = min(MIN, ans[key])
    print(MAX, MIN, sum([val for val in ans.values()]))
    return MAX - MIN


print(find_ans(40))
