N, K = map(int, input().split())
r = list(map(int, input().split()))
M = 1000000000000000009
for i in range(K):
    x = N % r[i]
    if x < M:
        M = x
        a = [i+1, N//r[i]]
print(a[0], a[1])
