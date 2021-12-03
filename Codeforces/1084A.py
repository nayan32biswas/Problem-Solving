n = int(input())

arr = [int(x) for x in input().split(" ")]

ans = 999999999
for x in range(1, n+1):
    temp = 0
    for a in range(1, n+1):
        each = (a-1)+(a-x)+(x-1)
        temp += each*arr[a-1]
    ans = min(ans, temp)
print(ans*2)
