inp = open("input.txt", "r")
inputs = inp.readlines()
arr = [int(num) for num in inputs[0].split(",")]


def series_sum(n):
    return (n * (n + 1)) / 2


def find_ans(arr):
    store = {}
    MIN, MAX = 1e9, 0
    for val in arr:
        if val not in store:
            store[val] = 1
        else:
            store[val] += 1
        MAX, MIN = max(MAX, val), min(MIN, val)

    ans = 1e20
    for key in range(MIN, MAX + 1):
        temp = 0
        for key_val in store:
            if key == key_val:
                continue
            # temp += abs(key - key_val) * store[key_val]
            temp += series_sum(abs(key - key_val)) * store[key_val]
        ans = min(ans, temp)
    return int(ans)


print(find_ans(arr))
