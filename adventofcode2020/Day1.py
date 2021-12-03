inp = open("input.txt", "r")
lines = inp.readlines()

lines = [int(data) for data in lines]

max = 0

for i in range(len(lines)):
    for j in range(i + 1, len(lines)):
        for k in range(j + 1, len(lines)):
            if lines[i] + lines[j] + lines[k] == 2020:
                print(lines[i], lines[j], lines[k])