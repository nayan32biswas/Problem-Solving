N = int(input())
data = []
for i in range(N):
    each = input().split(" ")
    data.append(each)
name = input()
for value in data:
    if name == value[0]:
        sum = 0
        size = 0
        for x in value[1:]:
            sum += float(x)
            size+=1
            
        print(f"{(sum/size):.2f}")
        break

