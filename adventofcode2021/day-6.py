inp = open("input.txt", "r")
inputs = inp.readlines()


arr = [int(num) for num in inputs[0].split(",")]


def find_ans(arr, days):
    ans = [0] * 9
    for val in arr:
        ans[val] += 1
    for each_day in range(days):
        ans[(each_day + 7) % 9] += ans[each_day % 9]
    return sum(ans)


print(find_ans(arr, 256))
