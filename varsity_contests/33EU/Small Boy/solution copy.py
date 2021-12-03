a, b = [int(x) for x in input().split(" ")]
if(a>9 or b>9):
    print(-1)
else:
    print(a*b)