#include <bits/stdc++.h>
using namespace std;

class ArticulationEdge {
private:
    bool check;
    int require;
    vector<bool>mark;
    vector<set<int>>graph;
public:
    void init(int node) {
        mark.resize(node);
        graph.resize(node);
    }
    void dfs(int node) {
        mark[node] = true;
        for(auto it : graph[node]) {
            if(check)
                return;
            if(!mark[it]) {
                if(it==require) {
                    check = true;
                    return;
                }
                dfs(it);
            }
        }
    }
    void add(int x, int y) {
        graph[x].insert(y);
        graph[y].insert(x);
    }
    void Remove(int x, int y) {
        graph[x].erase(y);
        graph[y].erase(x);
    }
    void run() {
        set< pair<int, int> > ans;
        require = 0;
        for(auto SET : graph) {
            for(auto it : SET) {
                if(require<it) {
                    check = false;
                    fill(mark.begin(), mark.end(), false);
                    Remove(require, it);
                    dfs(it);
                    if(check==false) {
                        ans.insert(make_pair(require, it));
                    }
                    add(require, it);
                }
            }
            require++;
        }
        printf("%d critical links\n", ans.size());
        for(auto it : ans) {
            printf("%d - %d\n", it.first, it.second);
        }
    }
};
int extractInteger(string str) {
    string temp="";
    for(auto it : str) {
        if(isdigit(it))
            temp+=it;
    }
    return atoi(temp.c_str());
}
ArticulationEdge aedge;
void solve(int node) {
    aedge.init(node);
    string str;
    int x, y;
    for(int i=0; i<node; i++) {
        scanf("%d", &x);
        cin>>str;
        int edge = extractInteger(str);
        for(int j=0; j<edge; j++) {
            scanf("%d", &y);
            aedge.add(x, y);
        }
    }
    aedge.run();
}
int main() {
    //freopen("input.txt", "r", stdin);
    int node, t=0;
    while(scanf("%d", &node) != EOF) {
        if(t++) puts("");
        solve(node);
    }
}

