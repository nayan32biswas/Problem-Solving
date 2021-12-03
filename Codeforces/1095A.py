n = int(input())
s = input()
inc = 0
i = 1
ans = []
while inc<n:
    ans.append(s[inc:inc+i])
    inc = i+inc
    i+=1
str = ""
for i in ans:
    str+=i[0]
print(str)