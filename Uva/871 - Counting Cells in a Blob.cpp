#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[30][30];
int row, clm[30];
inline int FF(int i, int J) {
    if(i<0 || i>=row || J<0 || J>=clm[i] || s[i][J]=='0')
        return 0;
    s[i][J] = '0';
    int ans=1;
    ans += FF(i-1, J);
    ans += FF(i-1, J-1);
    ans += FF(i-1, J+1);
    ans += FF(i, J-1);
    ans += FF(i, J+1);
    ans += FF(i+1, J);
    ans += FF(i+1, J-1);
    ans += FF(i+1, J+1);
    return ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, i, J, ans;
    scanf("%d\n", &test);
    for(int t=0; t<test; t++) {
        if(t) puts("");
        i = 0;
        while(gets(s[i]) && s[i][0]!=0) {
            clm[i] = strlen(s[i]);
            i++;
        }
        row = i, ans=0;
        for(i=0; i<row; i++) {
            for(J=0; J<clm[i]; J++)if(s[i][J]=='1'){
                ans = max(ans, FF(i, J));
            }
        }
        cout<<ans<<endl;
    }
}
