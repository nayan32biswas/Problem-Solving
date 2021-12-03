from collections import deque
test = int(input())
dque = deque()
for t in range(test):
    x = input().split(" ")
    if x[0]=="append":
        dque.append(int(x[1]))
    elif x[0]=="appendleft":
        dque.appendleft(x[1])
    elif x[0]=="pop":
        if len(dque)>0:
            dque.pop()
    elif x[0]=="popleft":
        if len(dque)>0:
            dque.popleft()
string = ""
for index, value in enumerate(dque):
    if index:
        string += " "
    string += str(value)
print(string)