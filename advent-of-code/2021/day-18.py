def get_input():
    return [
        [1, 1],
        [2, 2],
        [3, 3],
        [4, 4],
    ]


def magnitude(arr):
    a, b = arr
    ans = 0
    if isinstance(a, int):
        ans += 3 * a
    else:
        ans += 3 * magnitude(a)
    if isinstance(b, int):
        ans += 2 * b
    else:
        ans += 2 * magnitude(b)
    return ans


def transform(arr, new_val, depth_str, depth=0):
    a, b = arr
    if isinstance(a, int):
        pass


def add(a, b):
    new_arr = [a, b]

    return new_arr


def find_ans():
    input = get_input()
    arr = input[0]
    for i in range(1, len(input)):
        arr = add(arr, input[i])

    return magnitude(arr)


print(find_ans())
