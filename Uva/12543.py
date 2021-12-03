def Find():
    ans = ""
    while True:
        string = input()
        arr = ""
        for i in range(len(string)):
            if((string[i] >= 'a' and string[i] <= 'z') or (string[i] >= 'A' and string[i] <= 'Z') or (string[i] == '-' or string[i] == ' ')):
                arr += string[i]
        array = arr.split(" ")
        for value in array:
            if len(ans) < len(value):
                ans = value
            if value == "E-N-D":
                return ans.lower()

print(Find())
