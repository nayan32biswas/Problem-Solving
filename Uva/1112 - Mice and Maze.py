import queue

def bfs(graph, N, E, T):
    distances, visited, ans = [float("inf")]*(N+1), [0]*(N+1), [0]*(N+1)
    way = (1, -1)
    que = queue.PriorityQueue()
    distances[E] = 0
    ans[E] = 1
    que.put((0, E))
    while not que.empty():
        dis, now = que.get()
        if not visited[now]:
            for node, weight in graph[now]:
                node_distance = distances[now] + weight
                if not visited[node] and distances[node] > node_distance <= T :
                    ans[node] = 1
                    distances[node] = node_distance
                    que.put((node_distance, node))
            visited[now] = 1
    return sum(ans)


def solve():
    N = int(input())
    E = int(input())
    T = int(input())
    graph = [[] for _ in range(N+1)]
    M = int(input())
    for _ in range(M):
        x, y, w = [int(x) for x in input().split(" ")]
        graph[y].append((x, w))
    ans = bfs(graph, N, E, T)
    return ans


def main():
    test = int(input())
    for t in range(test):
        input()
        if (t):
            print()
        print(solve())


if __name__ == "__main__":
    main()
