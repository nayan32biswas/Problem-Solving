n = int(input())
str = input()
i = 0
while(i < (n-1) and str[i] <= str[i+1]):i += 1
print(str[:i]+str[i+1:])
