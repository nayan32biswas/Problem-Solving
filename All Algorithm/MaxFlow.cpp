#include <bits/stdc++.h>
using namespace std;
class FordFulkerson {
private:
    vector< vector<int> >graph;
public:
    bool BFS(vector<vector<int>>&residualCapacity, map<int, int>&parent, int source, int sink) {
        queue<int>Que;
        map<int, bool>visited;
        int node = residualCapacity.size();

        Que.push(source);
        visited[source] = true;
        while(!Que.empty()) {
            int current = Que.front();
            Que.pop();
            for(int it = 0; it<node; it++) {
                if(visited[it]==false && residualCapacity[current][it]>0) {
                    visited[it] = true;
                    parent[it] = current;
                    Que.push(it);
                    if(it==sink) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    int runMaxFlow(int source, int sink) {

        vector< vector<int> >residualCapacity;
        int node = graph.size();
        for(int i=0; i<node; i++) {
            residualCapacity.push_back(vector<int>());
        }
        for(int i=0; i<node; i++) {
            residualCapacity[i].resize(node);
            for(int j=0; j<node; j++) {
                residualCapacity[i][j] = graph[i][j];
            }
        }

        int maxFlow = 0;
        map<int, int>parent;
        vector<int>augmentedPath;
        vector< vector<int> >augmentedPaths;

        while(BFS(residualCapacity, parent, source, sink)) {
            augmentedPath.clear();
            int flow = INT_MAX;
            int v = sink;
            while(v != source) {
                augmentedPath.push_back(v);
                int u = parent[v];
                flow = min(flow, residualCapacity[u][v]);
                v = u;
            }
            augmentedPath.push_back(source);
            reverse(augmentedPath.begin(), augmentedPath.end());
            augmentedPaths.push_back(augmentedPath);

            maxFlow += flow;

            v = sink;
            while(v != source) {
                int u = parent[v];
                residualCapacity[u][v] -= flow;
                residualCapacity[v][u] += flow;
                v = u;
            }
        }
        print2D(augmentedPaths);
        return maxFlow;
    }
    void inputList() {
        int edge, u, v, w;
        cin>>edge;
        for(int i=0; i<edge; i++) {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
        }

    }
    void inputMatrix(int node) {
        int w;
        for(int i=0; i<node; i++) {
            for(int j=0; j<node; j++){
                scanf("%d", &graph[i][j]);
            }
        }
    }
    void print2D(vector<vector<int>>&vecInVec) {
        for(auto vec : vecInVec)
            print1D(vec);
        puts("");
    }
    void print1D(vector<int>&vec) {
        for(auto it : vec)
            cout<<it<<" ";
        cout<<endl;
    }
    void initialization(int node) {
        graph.clear();
        for(int i=0; i<node; i++) {
            graph.push_back(vector<int>());
        }
        for(int i=0; i<node; i++) {
            graph[i].resize(node);
        }
    }
    void add(int u, int v, int weight) {
        graph[u][v] = weight;
    }
};
int main() {
    freopen("input.txt", "r", stdin);
    FordFulkerson Graph;
    int node, u, v;

    scanf("%d", &node);
    Graph.initialization(node);
    Graph.inputList();


    scanf("%d%d", &u, &v);
    cout<<Graph.runMaxFlow(u, v)<<endl;

    return 0;
}
/**
4 5
0 1 3
0 2 2
1 3 4
2 1 2
2 3 1

0 3
*/
