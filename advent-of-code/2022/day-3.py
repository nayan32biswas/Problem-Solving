from string import ascii_lowercase, ascii_uppercase

inp = open("input.txt", "r")
inputs = inp.readlines()
inputs = [data.strip() for data in inputs]

store = {val: idx + 1 for idx, val in enumerate(ascii_lowercase)}
store.update({val: idx + 27 for idx, val in enumerate(ascii_uppercase)})


def solution_one():
    def find_match(str):
        count = [0 for _ in range(127)]

        for idx in range(len(str) // 2):
            count[ord(str[idx])] += 1

        for idx in range(len(str) // 2, len(str)):
            if count[ord(str[idx])]:
                return str[idx]
        return ""

    ans = 0
    for line in inputs:
        ans += store.get(find_match(line), 0)
    return ans


def solution_two():
    def find_match(str_1, str_2, str_3):
        count_one = {char: True for char in str_1}
        count_two = {char: True for char in str_2}
        for char in str_3:
            if char in count_one and char in count_two:
                return store[char]
        return 0

    ans = 0
    for idx in range(0, len(inputs), 3):
        ans += find_match(inputs[idx], inputs[idx + 1], inputs[idx + 2])
    return ans


# print(f"Solution 1: {solution_one()}")
print(f"Solution 2: {solution_two()}")
