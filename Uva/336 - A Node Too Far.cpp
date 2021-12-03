#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> > V;
inline int BFS(int Node, int Dist){
    queue<int>Q;
    map<int, int> visit;
    Q.push(Node);
    visit[Node]=0;
    while(Q.empty()==false){
        Node = Q.front(), Q.pop();
        int len = V[Node].size();
        for(int J=0; J<len; J++){
            int v = V[Node][J];
            if(!visit.count(v)){
                if(visit[Node]==Dist) return visit.size();
                visit[v]=visit[Node]+1;
                Q.push(v);
            }
        }
    }
    return visit.size();
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int Edge, x, y,  i, J, Case=1, chack;
    while(scanf("%d", &Edge)==1 && Edge){
        V.clear();
        while(Edge--){
            scanf("%d%d", &x, &y);
            V[x].push_back(y), V[y].push_back(x);
        }
        int Node, Dist, len = V.size();
        while(scanf("%d%d", &Node, &Dist)==2 && (Node || Dist)){
            chack = len - BFS(Node, Dist);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",Case++, chack, Node, Dist);
        }
    }
    return 0;
}
