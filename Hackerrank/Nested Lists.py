N = int(input())
data = []
for i in range(N):
    name = input()
    mark = float(input())
    data.append([mark, name])

data.sort( key=lambda data: data[0])
second = data[0][0]
for value in data:
    if second != value[0]:
        second = value[0]
        break
ans = []
# print(second)
for value in data:
    if second == value[0]:
        ans.append(value[1])
ans.sort()

for value in ans:
    print(value)