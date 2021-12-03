def rec(w, h, k):
    if w <= 0 or h <= 0 or k <= 0:
        return 0
    return (w*2+max(0, (h-2)*2))+rec(w-4, h-4, k-1)


w, h, k = [int(x) for x in input().split(" ")]
print(rec(w, h, k))
