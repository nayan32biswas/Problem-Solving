n = int(input())
t = [int(x) for x in input().split(" ")]
t = tuple(t)
print(hash(t))