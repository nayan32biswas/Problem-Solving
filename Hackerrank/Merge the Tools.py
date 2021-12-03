def Clear(foo):
    # print(foo)
    result = []
    for c in foo:
        if c not in result:
            result.append(c)
    return ''.join(result)

def merge_the_tools(string, k):
    for x in range(0, len(string), k):
        print("".join(Clear(string[x:x+k])))

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)