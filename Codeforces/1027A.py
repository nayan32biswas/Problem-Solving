def Check(a, b):
    a = [ord(a)-1, ord(a)+1]
    b = [ord(b)-1, ord(b)+1]
    for x in a:
        if x in b:
            return True
    for x in b:
        if x in a:
            return True

    return False


def palindrome(sss):
    n = len(sss)
    # Run loop from 0 to len/2
    for i in range(0, int(n/2)):
        if Check(sss[i], sss[n-i-1]) == False:
            return False
    return True


test = int(input())
for _ in range(test):
    n = int(input())
    sss = input()
    if palindrome(sss):
        print("YES")
    else:
        print("NO")
