inp = open("input.txt", "r")
inputs = inp.readlines()
inputs = [data.strip() for data in inputs]

each_carrying = 0
carrying_by_each = []

for str in inputs:
    if str.isdigit() is False:
        carrying_by_each.append(each_carrying)
        each_carrying = 0
    else:
        each_carrying += int(str)

if each_carrying > 0:
    carrying_by_each.append(each_carrying)

carrying_by_each.sort()

print(f"Solution 1: {carrying_by_each[-1]}")
print(f"Solution 2: {carrying_by_each[-3]+carrying_by_each[-2]+carrying_by_each[-1]}")
