#include <bits/stdc++.h>
using namespace std;
#define Size 100009
int mark[Size], n;
double ans;

vector<int>graph[Size];
double dfs(int node, int father){
    double sum=0, div=0;
    for(auto x : graph[node]){
        if(x==father) continue;
        div++;
        sum+=(1+dfs(x, node));
    }
    if(div==0.0) return 0;
    return sum/div;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int u, v, i;
    scanf("%d", &n);
    for(i=1; i<n; i++){
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<<fixed<<setprecision(7)<<dfs(1, 1)<<endl;
    return 0;
}

