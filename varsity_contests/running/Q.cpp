#include <bits/stdc++.h>
using namespace std;

class Dijkstra
{
private:
    int Size, source, inc;
    vector<vector<pair<int, int>>> graph;
    vector<bool> mark;

public:
    int MAXI;
    vector<long long> distance;
    void add(int from, int to, int weight)
    {
        graph[from].push_back(make_pair(weight, to));
        graph[to].push_back(make_pair(weight, from));
    }
    void run(int S)
    {
        pair<long long, int> current;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;

        fill(mark.begin(), mark.end(), false);
        fill(distance.begin(), distance.end(), MAXI);

        source = S;
        distance[source] = 0;
        Q.push(make_pair(0, source));
        while (!Q.empty())
        {
            current = Q.top();
            Q.pop();
            if (mark[current.second] == false)
            {
                for (auto now : graph[current.second])
                {
                    now.first += current.first;
                    if (distance[now.second] > now.first)
                    {
                        distance[now.second] = now.first;
                        Q.push(now);
                    }
                }
            }
            mark[current.second] = true;
        }
    }
    void init(int s)
    {
        graph.clear(), distance.clear(), mark.clear();
        Size = s, MAXI = INT_MAX;
        graph.resize(Size), distance.resize(Size), mark.resize(Size);
    }
};

int main()
{
    // freopen("input.txt", "r", stdin);
    int test, N, M, u, v, w;
    scanf("%d", &test);
    Dijkstra dij = Dijkstra();
    for (int t = 1; t <= test; t++)
    {
        scanf("%d%d", &N, &M);
        dij.init(N + 1);

        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            dij.add(u, v, w);
        }
        dij.run(1);
        printf("Case %d: ", t);
        if (dij.MAXI == dij.distance[N])
        {
            puts("Impossible");
        }
        else
        {
            printf("%lld\n", dij.distance[N]);
        }
    }
}