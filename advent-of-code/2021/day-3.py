inp = open("input.txt", "r")
inputs = inp.readlines()

inputs = [data.strip() for data in inputs]


def bool2int(arr):
    arr = reversed(arr)
    num = 0
    for i, j in enumerate(arr):
        num += int(j) << i
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
    ans = [1 if zeros[i] < ones[i] else 0 for i in range(arr_size)]
    gama = bool2int(ans)
    ans = [0 if val == 1 else 1 for val in ans]
    epsilon = bool2int(ans)

    return gama * epsilon


def filter_inputs(inputs, pos, com_val):
    return [val for val in inputs if val[pos] == com_val]


def find_value(inputs, com_val):
    input_for_oxigen = inputs
    line_size = len(inputs[0])
    for i in range(line_size):
        zero, one = 0, 0
        if len(input_for_oxigen) == 1:
            print(i)
            break
        for val in input_for_oxigen:
            if val[i] == "0":
                zero += 1
            elif val[i] == "1":
                one += 1
        if zero > one:
            if(com_val == "1"):
                input_for_oxigen = filter_inputs(input_for_oxigen, i, "0")
            else:
                input_for_oxigen = filter_inputs(input_for_oxigen, i, "1")
        elif one > zero:
            if(com_val == "1"):
                input_for_oxigen = filter_inputs(input_for_oxigen, i, "1")
            else:
                input_for_oxigen = filter_inputs(input_for_oxigen, i, "0")
        else:
            input_for_oxigen = filter_inputs(input_for_oxigen, i, com_val)
    return bool2int(input_for_oxigen[0])


def second(inputs):
    oxigen = find_value(inputs, "1")
    co2 = find_value(inputs, "0")
    return oxigen * co2


# print(first(inputs))
print(second(inputs))
