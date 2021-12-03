#include <bits/stdc++.h>
using namespace std;
char s[101][101];
bool v[101][101];
int row, col;
int ff(int i,int j) {
    if (i<0 || j<0 || i>=row || j>=col) return 0;
    if (v[i][j]) return 0;
    if (s[i][j]=='.') return 0;
    v[i][j]= 1;
    int ans=1;
    ans+=ff(i-1,j);
    ans+=ff(i-1, j-1);

    ans+=ff(i+1,j);
    ans+=ff(i-1, j+1);

    ans+=ff(i,j-1);
    ans+=ff(i+1, j-1);

    ans+=ff(i,j+1);
    ans+=ff(i+1,j+1);
    return ans;
}
int main()
{
    freopen("input.in","r",stdin);
    int n=9, ans, x, y, test, i, j, Max;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){

        Max = 0;
        ans = 0;
        scanf("%d%d", &row , &col);
        row;
        col;
        getchar();
        for(i=0; i<row; i++){
            for(j=0; j<col; j++)
                cin>>s[i][j];
        }
        for(i=0; i<row; i++){
            for(j=0; j<col; j++){
                if(v[i][j]==0){
                    ans = ff(i,j);
                }
                if(Max<ans) Max = ans;
            }
        }
        printf("Case %d: %d\n", t, Max);
        memset(s,0,sizeof(s));
        memset(v,0,sizeof(v));
    }
    return 0;
}
