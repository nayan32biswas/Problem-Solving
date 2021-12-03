def FtoC(F):
    return (5*F-160)/9
def CtoF(C):
    return (9/5)*C+32

test = int(input())
for t in range(1, test+1):
    l = [int(x) for x in input().split(" ")]
    # print(l)
    C = l[0]
    d = l[1]
    F = CtoF(C)+d
    print("Case {:}: {:.2f}".format(t, FtoC(F)))
