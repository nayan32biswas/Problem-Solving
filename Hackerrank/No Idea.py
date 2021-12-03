def lower_bound(array, key):
    n = len(array)
    start = 0
    end = n - 1
    mid = 0
    while start < end:
        mid = int((start + end) / 2)
        if array[mid] < key:
            start = mid + 1
        else:
            end = mid - 1
    ans = 0
    while mid >= 0 and array[mid] >= key:
        mid -= 1
    mid = max(mid, 0)
    while mid < n and array[mid] < key:
        mid += 1
    # return mid is a lower_bound
    while mid < n and key == array[mid]:
        mid += 1
        ans += 1
    return ans


def many(array, temp):
    ans = 0
    for x in temp:
        ans += lower_bound(array, x)
    return ans


def solve():
    num = tuple([int(x) for x in input().split(" ")])
    array = sorted([int(x) for x in input().split(" ")])
    A = [int(x) for x in input().split(" ")]
    B = [int(x) for x in input().split(" ")]
    a = many(array, A)
    b = many(array, B)
    print(a - b)


solve()