arr = input()
sstr = ""
for x in arr:
    if x.isupper():
        x = x.lower()
    elif x.islower():
        x = x.upper()
    sstr += x
print(sstr)
