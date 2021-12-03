def case():
    arr = [int(x) for x in input().split(" ")]
    temp = sorted(arr[4:])
    total = (arr[0]+arr[1]+arr[2]+arr[3])+((temp[2]+temp[1])/2)
    if(total >= 90):
        return "A"
    if(total >= 80):
        return "B"
    if(total >= 70):
        return "C"
    if(total >= 60):
        return "D"
    return "F"


test = int(input())
for t in range(test):
    print("Case", (str(t+1)+":"), case())
