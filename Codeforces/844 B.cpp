#include <bits/stdc++.h>
using namespace std;
int table[55][55];
int row, clm;
long long ans;
void call(int x, int y){
    int i;
    long long temp = 0;
    for(i=y+1, temp=0; i<clm; i++) if(table[x][y]==table[x][i]){
        temp++;
    }
    if(temp==1) ans++;
    else if(temp!=0) ans += (1<<temp)-1;
    for(i=x+1, temp=0; i<row; i++) if(table[x][y]==table[i][y]){
        temp++;
    }
    if(temp==1) ans++;
    else if(temp!=0) ans += (1<<temp)-1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j;
    scanf("%d%d", &row, &clm);
    ans = row*clm;
    for(i=0; i<row; i++){
        for(j=0; j<clm; j++)
            scanf("%d", &table[i][j]);
    }
    for(i=0; i<row; i++){
        for(j=0; j<clm; j++){
            call(i, j);
        }
    }
    cout<<ans<<endl;
    return 0;
}
