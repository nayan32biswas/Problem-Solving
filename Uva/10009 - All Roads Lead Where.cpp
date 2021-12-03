#include <bits/stdc++.h>
using namespace std;
map<string, vector<string> >graph;
map<string, string>path;
string findPath(string from, string to) {
    string str = "";
    while(path[to]!=from){
        str += to[0];
        to = path[to];
    }
    str += to[0];
    str += from[0];
    reverse(str.begin(), str.end());
    return str;
}
void BFS(string from, string to) {
    path.clear();
    queue<string>que;
    map<string, bool>mark;

    mark[from] = 1;
    que.push(from);

    while(!que.empty()) {
        string now = que.front();
        que.pop();
        for(auto it : graph[now]){
            if(mark[it]==0){
                mark[it] = 1;
                path[it] = now;
                que.push(it);
            }
        }
    }
}
void Case() {
    int m, n;
    scanf("%d%d", &m, &n);
    graph.clear();
    string from, to;
    for(int i=0; i<m; i++) {
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    while(n--) {
        cin>>from>>to;
        BFS(from, to);
        cout<<findPath(from, to)<<endl;
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for(int t=0; t<test; t++) {
        if(t)
            puts("");
        Case();
    }
    return 0;
}
