check = True


def each(arr, i, value):
    global check
    if(i > 4 or check == True):
        if(value == 23):
            check = True
        return
    each(arr, i+1, value+arr[i])
    each(arr, i+1, value-arr[i])
    each(arr, i+1, value*arr[i])


def perm(a, k=0):
    global check
    if k == len(a) or check == True:
        if(check == True):
            return
        each(a, 1, a[0])
        if(check == True):
            return
    else:
        for i in range(k, len(a)):
            a[k], a[i] = a[i], a[k]
            perm(a, k+1)
            if(check == True):
                return
            a[k], a[i] = a[i], a[k]


arr = [int(x) for x in input().split(" ")]
while arr[0] != 0:
    check = False
    perm(arr)
    print("Possible") if check else print("Impossible")
    arr = [int(x) for x in input().split(" ")]