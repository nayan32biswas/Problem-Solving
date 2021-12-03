import math
test = int(input())
for t in range(test):
    l = int(input())
    w, r = [l*0.6, l*0.2]
    totalArea, circle = [l*w, math.pi*r*r]
    print("{:.2f} {:.2f}".format(circle, totalArea-circle))
