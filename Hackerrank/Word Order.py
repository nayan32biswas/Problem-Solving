def lower_bound(array, key):
    n = len(array)
    start = 0
    end = n-1
    mid = 0
    while start<end:
        mid = int((start+end)/2)
        if array[mid]<key:
            start = mid+1
        else:
            end = mid-1
    ans = 0
    while mid>=0 and array[mid]>=key:mid-=1
    mid = max(mid, 0)
    while mid<n and array[mid]<key:mid+=1
    # return mid is a lower_bound
    while mid<n and key==array[mid]:
        array[mid]+='.'
        mid += 1
        ans += 1
    return ans


def solve():
    n = int(input())
    un_arr = []
    for _ in range(n): un_arr.append(input())
    so_arr = sorted(un_arr)
    ans = ""
    for val in un_arr:
        temp = lower_bound(so_arr, val)
        if temp>0:
            ans = ans+" "+str(temp)

    ans = ans.split(" ")[1:]
    print(len(ans))
    print(" ".join(ans))
    
solve()
    
