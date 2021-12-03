#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int>V[111], ans;
bool visit[111], F_visit[111];
void top_sort(int node) {
    if(!visit[node]) {
        int i, len=V[node].size();
        visit[node]=1;
        for(i=0; i<len; i++){
            top_sort(V[node][i]);
        }
        ans.push_back(node);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    int x, y, i, J, test, Max=0, len;
    while(scanf("%d", &test)==1 && test) {
        if(test>Max) Max = test;
        while(test--) {
            scanf("%d", &x); if(!x) continue;
            while(scanf("%d", &y)==1 && y) {
                V[x].push_back(y);
                F_visit[y] = 1;
                F_visit[x] = 1;
                x = y;
            }
        }
    }
    while(scanf("%d", &test)==1 && test) {
        while(test--) {
            memset(visit, 0, sizeof(visit));
            scanf("%d", &x);
            for(i=0; i<=Max; i++)
                if(F_visit[i])
                    top_sort(i);

            for(i=0, len=ans.size(); i<len; i++){
                if(i) printf(" ");
                printf("%d", ans[i]);
            }puts("");
            ans.clear();
        }
    }
    return 0;
}
/**
7
1 2 0
2 3 4 0
3 1 0
4 5 0
5 4 0
6 7 0
7 6 0
0
7 1 2 3 4 5 6 7
0



2 6 7
2 6 7
2 6 7
5 1 2 3 6 7
5 1 2 3 6 7
5 1 2 3 4 5
5 1 2 3 4 5
*/
