import queue

def bfs(RV, L, U):
    visited, distance = [0]*10000, [0]*10000
    que = queue.Queue()
    visited[L] = 1
    distance[L] = 0
    que.put(L)
    while(not que.empty()):
        parent = que.get()
        for button in RV:
            next = (parent+button)%10000
            if (not visited[next]):
                visited[next] = 1
                distance[next] = distance[parent]+1
                if next == U:
                    return distance[next]
                que.put(next)
    return "Permanently Locked"


def solve(L, U, R):
    RV = [int(x) for x in input().split(" ")]
    return bfs(RV, L, U)


def main():
    test = 1
    while(True):
        L, U, R = [int(x) for x in input().split(" ")]
        if L == 0 and U == 0 and R == 0:
            return
        print(f"Case {test}: {solve(L, U, R)}")
        test += 1


if __name__ == "__main__":
    main()
