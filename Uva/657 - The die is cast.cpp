#include <bits/stdc++.h>
using namespace std;
char s[60][60];
int row, cloum, ans;
inline void floadfill(int i, int J);
inline void fload(int i, int J);
int main()
{
    //freopen("input.txt", "r", stdin);
    int test=1, i, J, k, arr[1000];
    while(scanf("%d%d", &row, &cloum)==2 && row && cloum) {
        for(int i=0; i<cloum; i++){
            scanf("%s", s[i]);
        }
        printf("Throw %d\n", test++);
        for(i=0, k=0; i<cloum; i++){
            for(J=0; J<row; J++){
                if(s[i][J]=='*' || s[i][J]=='X'){
                    ans = 0;
                    fload(i, J);
                    arr[k++] = ans;
                }
            }
        }
        sort(arr, arr+k);
        for(i=0; i<k; i++){
            if(i) cout<<' ';
            printf("%d", arr[i]);
        }
        puts("\n");
    }
    return 0;
}
inline void floadfill(int i, int J)
{
    if(s[i][J]=='.' || i<0 || J<0 || i>=cloum || J>=row)
        return;
    if(s[i][J]=='.' || s[i][J]=='*') return;
    s[i][J] = '*';

    floadfill(i-1,J);
    floadfill(i,J+1);
    floadfill(i,J-1);
    floadfill(i+1,J);
    return;
}
inline void fload(int i, int J)
{
    if(s[i][J]=='.' || i<0 || J<0 || i>=cloum || J>=row)
        return;
    if(s[i][J]=='X'){
        ans++;
        floadfill(i, J);
    }
    s[i][J]='.';

    fload(i-1,J);
    fload(i,J+1);
    fload(i,J-1);
    fload(i+1,J);
    return;
}
