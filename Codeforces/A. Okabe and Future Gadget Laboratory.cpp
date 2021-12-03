#include <bits/stdc++.h>
using namespace std;
int arr[55][55], n;
bool check(int x, int y, int num){
    int i, j;
    for(i=0; i<n; i++)if(i!=x){
        for(j=0; j<n; j++)if(j!=y){
            if(arr[i][y]+arr[x][j]==num)return true;
        }
    }
    return false;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int i=0; i<n; i++)for(int j=0; j<n; j++) scanf("%d", &arr[i][j]);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)if(arr[i][j]!=1){
            if(check(i, j, arr[i][j])==false)return puts("NO"), 0;
        }
    }
    puts("YES");
}
