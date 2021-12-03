if __name__ == '__main__':
    s = input()
    ans = ["False", "False", "False", "False", "False"]
    for x in s:
        if x.isalnum():
            ans[0] = "True"
        if x.isalpha():
            ans[1] = "True"
        if x.isdigit():
            ans[2] = "True"
        if x.islower():
            ans[3] = "True"
        if x.isupper():
            ans[4] = "True"
    for x in ans:
        print(x)