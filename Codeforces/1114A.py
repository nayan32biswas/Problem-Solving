def solve():
    x, y, z = [int(x) for x in input().split(" ")]
    a, b, c = [int(x) for x in input().split(" ")]
    if(x>a):
        return False
    a -= x
    if(a+b<y or a+b+c<y+z):
        return False
    return True
if(solve()):
    print("YES")
else:
    print("NO")