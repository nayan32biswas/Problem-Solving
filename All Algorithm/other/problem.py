import math

test = int(input())
for case in range(test):
    n = int(input())
    b = math.sqrt(2)
    a = math.sqrt((n**2+((n-2)**2)))/2
    h = math.sqrt((b/2)**2+a**2)
    A  = 0.5*b*h
    A-=.5
    print(f"Case {case+1}: {int(A*4)}")