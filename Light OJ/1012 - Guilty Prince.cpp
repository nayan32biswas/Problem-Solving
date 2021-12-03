#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int row, cloum;
bool visit[22][22], ck;
char s[22][22];
int fload(int i, int J)
{
    if(i<0 || J<0 || i>=cloum || J>=row) return 0;
    if(visit[i][J] || s[i][J]=='#') return 0;
    visit[i][J] = 1;
    int ans=1;
    ans += fload(i-1, J);
    ans += fload(i, J-1);
    ans += fload(i, J+1);
    ans += fload(i+1, J);
    return ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, i, J;
    scanf("%d\n", &test);
    for(int t=1; t<=test; t++){
        scanf("%d%d\n", &row, &cloum);
        for(i=0; i<cloum; i++){
            scanf("%s", s[i]);
            //cout<<s[i]<<endl;
        }
        memset(visit, 0, sizeof(visit));
        for(i=0, ck=false; i<cloum; i++) {
            for(J=0; J<row; J++) {
                if(s[i][J]=='@'){
                    printf("Case %d: %d\n", t, fload(i, J));
                    ck=true;
                    break;
                }
            }
            if(ck) break;
        }
    }

    return 0;
}
