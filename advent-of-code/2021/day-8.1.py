inp = open("input.txt", "r")
inputs = inp.readlines()


def extract_data(line):
    left, right = line.strip().split("|")
    return (left.strip().split(" "), right.strip().split(" "))


input = [extract_data(num) for num in inputs]


def count_char(arr, chr):
    count = 0
    for word in arr:
        if chr in word:
            count += 1
    return count


def detect_number(data):
    global base_line
    store = {}
    for line in data:
        x = len(line)
        if x not in store:
            store[x] = [line]
        else:
            store[x].append(line)
    tp, tl, tr, md, bl, br, bt = "", "", "", "", "", "", ""

    # Defind top right and bottom right from one
    string = store[2][0]
    count = count_char(store[6], string[0])
    if count == 3:
        br, tr = string[0], string[1]
    else:
        br, tr = string[1], string[0]

    # Define top from seven
    for x in store[3][0]:
        if x != tr and x != br:
            tp = x

    # Define top left and mid from four
    for x in store[4][0]:
        if x not in [tr, br]:
            count = count_char(store[6], x)
            if count == 3:
                tl = x
            elif count == 2:
                md = x

    # Define bottom left and bottom from eight
    for x in store[7][0]:
        if x not in [tp, tl, tr, md, br]:
            count = count_char(store[5], x)
            if count == 3:
                bt = x
            elif count == 1:
                bl = x
    return {"tp": tp, "tl": tl, "tr": tr, "md": md, "bl": bl, "br": br, "bt": bt}


def second(input):
    ans = 0
    for line in input:
        num, temp = 0, 0
        number = detect_number(line[0])

        pos = len(line[1]) - 1
        for word in line[1]:
            size = len(word)
            temp = 0
            if size == 2:
                temp = 1
            elif size == 3:
                temp = 7
            elif size == 4:
                temp = 4
            elif size == 7:
                temp = 8
            elif size == 5:
                if number["tl"] not in word and number["br"] not in word:
                    temp = 2
                elif number["tl"] not in word and number["bl"] not in word:
                    temp = 3
                else:
                    temp = 5
            elif size == 6:
                if number["md"] not in word:
                    temp = 0
                elif number["tr"] not in word:
                    temp = 6
                else:
                    temp = 9
            num += temp * (10 ** pos)
            pos -= 1
        # print(num)
        ans += num
    return ans


print(second(input))

"""
{
    "tp": "a",  # Top
    "tl": "b",  # Top left
    "tr": "c",  # Top right
    "md": "d",  # Mid
    "bl": "e",  # Bottom left
    "br": "f",  # Bottom right
    "bt": "g",  # Bottom
}
"""
