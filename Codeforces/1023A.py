def solve():
    m = [int(x) for x in input().split(" ")][1]
    a = input().split("*")
    b = input()
    if len(a) == 1:
        if a[0] == b:
            return 1
        return 0
    f, l = [len(a[0]), len(a[1])]
    if f+l > m:
        return False
    if a[0] == b[:f] and a[1] == b[m-l:]:
        return True
    return False


if solve():
    print("YES")
else:
    print("NO")
