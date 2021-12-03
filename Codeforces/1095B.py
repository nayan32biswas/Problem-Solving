def solve():
    n = int(input())
    arr = [int(x) for x in input().split(" ")]
    if n==int(2):
        print(0)
        return 0
    arr.sort()
    max = arr[-2] - arr[0]
    max1 = arr[-1] - arr[1]
    print(min(max, max1))
solve()
