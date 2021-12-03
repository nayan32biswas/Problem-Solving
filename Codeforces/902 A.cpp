#include <bits/stdc++.h>
using namespace std;
#define Size 105
bool arr[Size];
void Fill(int i, int len){
    if(i) i++;
    for(; i<=len; i++) arr[i]=true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, x, y;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        Fill(x, y);
    }
    //for(int i=0; i<=m; i++) printf("%d ", arr[i]);
    if(!arr[m]) return puts("NO"), 0;
    for(int i=0; i<m; i++)
        if(!arr[i]) return puts("NO"), 0;

    return puts("YES"), 0;
}

