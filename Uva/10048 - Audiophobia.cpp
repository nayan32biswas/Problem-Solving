#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> ppi;

struct data{
    int node1, node2, dis;
    bool operator <(data D){
        return dis<D.dis;
    }
};

vector<data>graph;
vector<ppi>tree[101];

int SET[101];
int Find(int r){
    if(r==SET[r]) return r;
    else SET[r] = Find(SET[r]);
    return SET[r];
}
void MST(int C){
    int i, x, y;
    for(i=0; i<=C; i++) SET[i]=i, tree[i].clear();
    sort(graph.begin(), graph.end());
    for(data node : graph){
        x = Find(node.node1);
        y = Find(node.node2);
        if(x!=y){
            SET[x] = y;
            tree[node.node1].push_back(make_pair(node.node2, node.dis));
            tree[node.node2].push_back(make_pair(node.node1, node.dis));
        }
    }
}

bool AllRadyMarked[101];
int ans[101][101];

int bfs(int to){
    memset(ans[to], 0, sizeof(ans[to]));
    int now, len, i, past;
    int Next, dis;
    queue<int>Q;
    Q.push(to);
    while(!Q.empty()){
        now = Q.front(); Q.pop();
        len = tree[now].size();
        past = ans[to][now];
        for(i=0; i<len; i++){

            Next = tree[now][i].first;
            dis = tree[now][i].second;

            if(!ans[to][Next]){
                ans[to][Next] = max(past, dis);
                Q.push(Next);
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int C, S, Q, i, j, test=0;
    data node;
    while(scanf("%d%d%d", &C, &S, &Q) && (C && S && Q)){
        graph.clear();
        for(i=0; i<S; i++){
            scanf("%d%d%d", &node.node1, &node.node2, &node.dis);
            graph.push_back(node);
        }
        MST(C);
        if(test) puts("");
        printf("Case #%d\n", ++test);
        while(Q--){
            scanf("%d%d", &C, &S);
            if(!AllRadyMarked[C]) bfs(C);
            if(ans[C][S]) printf("%d\n", ans[C][S]);
            else puts("no path");
        }
    }
    return 0;
}

