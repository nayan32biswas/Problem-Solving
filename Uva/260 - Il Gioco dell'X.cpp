#include <bits/stdc++.h>
using namespace std;

char s[209][209], ans;
bool visit[205][205], ck;
int row;

inline void ff(int i, int J)
{
    if(i<0 || J<0 || i>row || J>row || visit[i][J]==1 || s[i][J]!='b') return;

    if(i==row && s[i][J]=='b'){ ans='B'; return;}
    visit[i][J] = 1;

    ff(i-1, J-1);
    ff(i-1, J);
    ff(i, J-1);
    ff(i, J+1);
    ff(i+1, J);
    ff(i+1, J+1);
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t=0;
    while(scanf("%d\n", &row)==1 && row) {
        for(int i=0; i<row; i++){
            scanf("%s", s[i]);
        }
        ans = 'W', row--;
        memset(visit, 0, sizeof(visit));

        for(int i=0; i<row; i++){
            if(!visit[0][i] && s[0][i]=='b'){
                ff(0, i);
            }
        }
        printf("%d %c\n", ++t, ans);
    }
    return 0;
}

