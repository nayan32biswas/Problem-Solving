while True:
    n = int(input())
    if(n == 0):
        break
    a, b, pos, odd = [0, 0, 0, 0]
    while n > 0:
        if n & 1 == True:
            odd += 1
            if odd & 1 == True:
                a += 2**pos
            else:
                b += 2**pos
        pos += 1
        n //= 2
    print(a, b)
