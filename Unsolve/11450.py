ans = 0


def rec(array, M, C, sum):
    if(C < 0):
        return
    global ans
    # print(C, sum, ans)
    for it in array[C]:
        # print("for each model: ", x)
        if it+sum > M:
            return
        if(C == 0):
            ans = max(ans, it+sum)
        rec(array, M, C-1, it+sum)


def solve():
    for _ in range(int(input())):
        array = []
        # Input start
        M, C = [int(x) for x in input().split(" ")]
        for _ in range(C):
            array.append((([int(x) for x in input().split(" ")])[1:]))
            array[-1].sort()
        global ans
        ans = 0
        rec(array, M, C-1, 0)
        if ans == 0:
            print("no solution")
        else:
            print(ans)


solve()
"""
3
100 4
3 8 6 4
2 5 10
4 1 3 3 7
4 50 14 23 8
20 3
3 4 6 8
2 5 10
4 1 3 5 5
5 3
3 6 4 8
2 10 6
4 7 3 1 7
"""
