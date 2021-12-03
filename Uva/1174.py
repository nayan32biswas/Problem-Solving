def eachSet(graph):
    input()
    m = int(input())
    n = int(input())
    graph[:] = []
    dictonary = {}
    point = 1
    # print(graph)
    for _ in range(n):
        x, y, w = input().split(" ")
        w = int(w)
        if(dictonary.get(x) == None):
            dictonary[x] = point
            x = point
            point += 1
        else:
            x = dictonary.get(x)
        if(dictonary.get(y) == None):
            dictonary[y] = point
            y = point
            point += 1
        else:
            y = dictonary.get(y)
        graph.append((x, y, w))


def check(mark, r):
    if(mark[r] == r):
        return r
    return check(mark, mark[r])


def kruskal(graph):
    graph.sort(key=lambda x: x[2:])
    mark = list(range(0, len(graph)+1))
    # print(mark)

    total = 0
    for it in graph:
        x = check(mark, it[0])
        y = check(mark, it[1])
        if x != y:
            mark[x] = y
            total += it[2]
    print(total)


def solve():
    graph = []
    test = int(input())
    for t in range(test):
        eachSet(graph)
        if t:
            print()
        kruskal(graph)


solve()
