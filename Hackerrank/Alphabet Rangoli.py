abc = "abcdefghijklmnopqrstuvwxyz"

def genarete(now, max):
    string = ""
    for i in range(now):
        string += abc[max-i-1]
    string = "-".join(list(string))
    string = string+"".join(reversed(list(string[:len(string)-1])))
    return string
def print_rangoli(max):
    ans = []
    for i in range(1, max):
        ans.append(genarete(i, max))
    mid = genarete(max, max)
    size = len(mid)
    for x in ans:
        print(x.center(size, "-"))
    print(mid)
    ans.reverse()
    for x in ans:
        print(x.center(size, "-"))

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)