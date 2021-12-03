def make_string(ans):
    sss = ""
    for index, value in enumerate(ans):
        if(index):
            sss += " "
        sss += str(value)
    return sss


def each():
    n, m, k = [int(x) for x in input().split(" ")]
    arr = [[int(value), index]
           for index, value in enumerate(input().split(" "))]
    arr.sort()
    sum = 0
    len = (n-min(m*k, n))-1
    for i in range(n-1, len, -1):
        sum += arr[i][0]
        arr[i][0] = None
    arr.sort(key=lambda x: x[1:2])
    mmm = m
    ans = []
    for i in range(n):
        if(arr[i][0] == None):
            mmm -= 1
        if(mmm == 0):
            mmm = m
            ans.append(arr[i][1]+1)
    ans.pop()
    print(sum)
    ans = make_string(ans)
    print(ans)


each()
