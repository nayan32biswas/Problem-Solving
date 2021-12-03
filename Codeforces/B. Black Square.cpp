#include<bits/stdc++.h>
using namespace std;
char str[105][105];

int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, n, m, x=200, X=0, y=200, Y=0, ans, black=0;
    bool ck=true;
    scanf("%d%d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%s", str[i]);
        for(j=0; j<m; j++)if(str[i][j]=='B'){
            x = min(x, i);
            X = max(X, i);
            y = min(y, j);
            Y = max(Y, j);
            black++;
        }
    }
    if(!black)return 0*puts("1");
    ans = max((X-x)+1, (Y-y)+1);
    if(ans>min(n, m))return 0*puts("-1");
    cout<<(ans*ans-black)<<endl;
    return 0;
}
