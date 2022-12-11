inp = open("input.txt", "r")
inputs = inp.readlines()
inputs = [data.strip() for data in inputs]

"""
A & X = Rock
B & Y = Paper
C & Z = Scissors

X = lose
Y = drow
Z = win
"""

values = {"A": 1, "X": 1, "B": 2, "Y": 2, "C": 3, "Z": 3}
lose = {"AZ": 1, "CY": 1, "BX": 1}


def solution_one():
    total_point = 0
    for each in inputs:
        a, b = each[0], each[2]
        total_point += values[b]

        if values[a] == values[b]:
            total_point += 3
        elif f"{a}{b}" not in lose:
            total_point += 6
    return total_point


def solution_two():
    total_point = 0
    for each in inputs:
        a, b = each[0], each[2]
        if b == "X" and a == "A": total_point += 0 + 3
        elif b == "X" and a == "B": total_point += 0 + 1
        elif b == "X" and a == "C": total_point += 0 + 2

        elif b == "Y" and a == "A": total_point += 3 + 1
        elif b == "Y" and a == "B": total_point += 3 + 2
        elif b == "Y" and a == "C": total_point += 3 + 3

        elif b == "Z" and a == "A": total_point += 6 + 2
        elif b == "Z" and a == "B": total_point += 6 + 3
        elif b == "Z" and a == "C": total_point += 6 + 1

    return total_point


# print(f"Solution 1: {solution_one()}")
print(f"Solution 2: {solution_two()}")
