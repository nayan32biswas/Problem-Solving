nk = [int(x) for x in input().split(" ")]

arr = [int(x) for x in input().split(" ")]
arr.sort()
arr.reverse()
subtract = 0

while len(arr) > 0 and nk[-1]:
    while len(arr) > 0 and arr[-1] <= subtract:
        arr.pop()
    if(len(arr) == 0):
        break
    temp = arr.pop()-subtract
    subtract += temp
    print(temp)
    nk[-1] -= 1

for i in range(nk[-1]):
    print(0)
