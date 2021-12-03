#include <bits/stdc++.h>
using namespace std;
int ans[1009][1009];
void LCS(char *s, char *sub) {
    int len, len1, i, j, Max=0;
    len = strlen(s);  len1 = strlen(sub);
    if(len<len1)return LCS(sub, s);
    memset(ans, 0, sizeof(ans));
    for(i=0; i<len1; i++) {
        for(j=0; j<len; j++) {
            if(sub[i]==s[j]){
                ans[i+1][j+1] = ans[i][j]+1;
                Max = max(Max, ans[i+1][j+1]);
            }
            else{
                ans[i+1][j+1] = max(ans[i+1][j], ans[i][j+1]);
            }
        }
    }
    cout<<Max<<endl;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    char s[1100], sub[1100];
    while(gets(s)) {
        gets(sub);
        LCS(s, sub);
    }
    return 0;
}
