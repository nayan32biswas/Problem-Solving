#include <bits/stdc++.h>
using namespace std;
#define Size 1000009
vector<int>COUNT[Size];
int main()
{
    int n, m, k, v, x;
    while(cin>>n>>m){
        for(int i=0; i<Size; i++) COUNT[i].clear();
        for(int i=1; i<=n; i++){
            scanf("%d", &x);
            COUNT[x].push_back(i);
        }

        for(int t=0; t<m; t++){
            scanf("%d%d", &k, &v);
            k--;
            if(COUNT[v].size()>k) printf("%d\n", COUNT[v][k]);
            else puts("0");
        }
    }
    return 0;
}
