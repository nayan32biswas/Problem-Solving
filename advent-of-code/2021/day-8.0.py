inp = open("input.txt", "r")
inputs = inp.readlines()


def extract_data(line):
    left, right = line.strip().split("|")
    return (left.strip().split(" "), right.strip().split(" "))


input = [extract_data(num) for num in inputs]


def first(input):
    ans = 0
    for line in input:
        for word in line[1]:
            if len(word) in [2, 3, 4, 7]:
                ans += 1
    return ans


print(first(input))
