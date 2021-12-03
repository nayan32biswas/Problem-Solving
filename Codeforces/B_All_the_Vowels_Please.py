string = [
    "aeiou",
    "eioua",
    "iouae",
    "ouaei",
    "uaeio"
]

def find_n(fact, MAX):
    n = MAX
    size = len(fact)
    break_now = False
    for i in range(0, size):
        if fact[i]>=5:
            break_now, n = True, fact[i]
        for j in range(i+1, size):
            val = fact[i]*fact[j]
            if val >= 5:
                break_now, n = True, min(n, val)
            for k in range(j+1, size):
                break_now, val = True, fact[i]*fact[j]*fact[k]
                if val >= 5:
                    n = min(n, val)
    return n

def find_n_m(num):
    copy_num = num
    fact = []
    while num > 1 and num % 2 == 0:
        num //= 2
        fact.append(2)
    for i in range(3, num, 2):
        if i*i > num:
            break
        while num % i == 0:
            num //= i
            fact.append(i)
    if num > 1:
        fact.append(num)
    n = find_n(fact, 100000)
    # print(n, end=", ")
    fact.reverse()
    n = min(find_n(fact, n), n)
    # print(n, end=", ")
    return n, copy_num//n

def solve(k):
    n, m = find_n_m(k)
    if n<5 or m<5:
        return -1
    ans = list(string)
    m-=5
    n-=5
    while m>=5:
        for i in range(5):
            ans[i]+=string[i]
        m-=5
    while m>0:
        for i in range(5):
            ans[i]+=string[i][0]
        m-=1
    demo = ans[0]
    for _ in range(n):
        ans.append(demo)
    final_ans = ""
    for value in ans:
        final_ans += value
    return final_ans

k = int(input())
print(solve(k))
