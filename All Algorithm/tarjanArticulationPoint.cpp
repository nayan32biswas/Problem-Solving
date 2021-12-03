#include <bits/stdc++.h>
using namespace std;
class tarjanArticulationPoint {
    int time;
    vector<bool>mark;
    vector<int>point;
    vector< int > parents;
    vector< vector<int> > graph;
    vector< pair<int, int> >hiLowTime, articulationEdge;
public:
    void init(int Size) {
        time = 0;
        mark.resize(Size+1);
        graph.resize(Size+1);
        parents.resize(Size+1);
        hiLowTime.resize(Size+1);
    }
    void add(int from, int to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    void dfs(int node) {
        mark[node] = true;
        hiLowTime[node] = make_pair(time, time);
        time++;
        int child = 0;
        bool isArticul = false;
        for(auto it : graph[node]) {
            if(it==parents[node])
                continue;
            if(!mark[it]) {
                child++;
                parents[it] = node;
                dfs(it);
                if(hiLowTime[node].first <= hiLowTime[it].second) {
                    isArticul = true;
                } else {
                    hiLowTime[node].second = min(hiLowTime[node].second, hiLowTime[it].second);
                }
            } else {
                hiLowTime[node].second = min(hiLowTime[node].second, hiLowTime[it].first);
            }
        }
        if((parents[node] == node && child>=2) || (parents[node] != node && isArticul)) {
            point.push_back(node);
        }
    }
    void call(int node) {
        point.clear();
        fill(mark.begin(), mark.end(), 0);
        for(int i=0; i<node; i++)
            parents[i] = i;
        dfs(3);
        for(auto it : point)
            cout<<it<<" ";
        puts("");
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    tarjanArticulationPoint tap;
    int node, edge, x, y;
    cin>>node>>edge;
    tap.init(node);
    for(int i=0; i<edge; i++) {
        cin>>x>>y;
        tap.add(x, y);
    }
    tap.call(node);
    return 0;
}
