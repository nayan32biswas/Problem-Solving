m = [int(x) for x in input().split(" ")][1]
each_day = [int(x) for x in input().split(" ")]
page = m
ans = ""
for x in each_day:
    if x < page:
        ans += " 0"
        page -= x
    elif x == page:
        ans += " 1"
        page = m
    else:
        ppp = 1
        x -= page

        ppp += (x//m)
        page = m-(x % m)
        ans += " "+str(ppp)

print(ans[1:])
