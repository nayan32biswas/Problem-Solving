n, k = map(int, input().split())
d = k - 1
while n % d:
    d -= 1
# print(n//k, d)
print(n // d * k + d)
