#include <bits/stdc++.h>
using namespace std;
#define Size 100009
int dp[Size][5], parent[Size];
vector<int>graph[Size];
int F(int node, int isGurd)
{
    if(graph[node].size()==0) return 0;
    if(dp[node][isGurd]!=-1)
        return dp[node][isGurd];
    int sum=0;
    for(auto v : graph[node])if(v!=parent[node]){
        parent[v] = node;
        if(isGurd == 0) sum += F(v, 1);
        else sum += min(F(v, 1), F(v, 0));
    }
    return dp[node][isGurd] = sum+isGurd;
}
int main()
{
    freopen("input.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));
    int n, x, y;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cout<<min( F(1, 1), F(1, 0) )<<endl;
    return 0;
}
