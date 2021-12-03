x = int(input())
if x==1:
    print("-1")
else:
    if x&1:
        x -= 1
    print(x, 2)