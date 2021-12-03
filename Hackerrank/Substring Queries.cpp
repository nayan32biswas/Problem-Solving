#include <bits/stdc++.h>
using namespace std;
int lcs(string X, string Y, int m, int n )
{
    int LCSuff[m+1][n+1], result=0, i, J;

    for (i=0; i<=m; i++) {
        for(J=0; J<=n; J++) {
            if (i==0 || J== 0) LCSuff[i][J] = 0;
            else if (X[i-1] == Y[J-1]) {
                LCSuff[i][J] = LCSuff[i-1][J-1] + 1;
                result = max(result, LCSuff[i][J]);
            }
            else{
                LCSuff[i][J]=0;
            }
        }
    }
    return result;
}
string s[100009];
int main()
{
    freopen("input.txt", "r", stdin);
    int n, q, i, J, x, y, ans;
    int len[50009];
    scanf("%d%d", &n, &q);
    for(i=0; i<n; i++){
        cin>>s[i];
        len[i] = s[i].size();
    }
    for(i=0; i<q; i++){
        scanf("%d%d", &x, &y);
        ans = lcs(s[x], s[y], len[x], len[y]);
        printf("%d\n", ans);
    }
    return 0;
}
