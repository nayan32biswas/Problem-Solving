inp = open("input.txt", "r")
inputs = inp.readlines()

inputs = [data.strip() for data in inputs]


def max(zero, one):
    if zero > one:
        return 0
    else:
        return 1


def bool2int(arr):
    arr = reversed(arr)
    num = 0
    for i, j in enumerate(arr):
        num += j << i
    return num


def first(inputs):
    arr_size = len(inputs[0])
    zeros = [0] * arr_size
    ones = [0] * arr_size
    for value in inputs:
        for i in range(arr_size):
            if value[i] == "0":
                zeros[i] += 1
            else:
                ones[i] += 1
    ans = [max(zeros[i], ones[i]) for i in range(arr_size)]
    gama = bool2int(ans)
    ans = [0 if val == 1 else 1 for val in ans]
    epsilon = bool2int(ans)

    return gama * epsilon


print(first(inputs))
