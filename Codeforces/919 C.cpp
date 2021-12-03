#include <bits/stdc++.h>
using namespace std;
#define Size 2005
char str[Size][Size];
long long ans, ans1;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, x;
    cin>>n>>m>>k;
    for(int i=0; i<n; i++)scanf("%s", str[i]);
    for(int i=0; i<n; i++){
        x = 0;
        for(int j=0; j<m; j++){
            if(str[i][j]=='.')x++, ans1++;
            else {
                if(x>=k) ans += x-k+1;
                x = 0;
            }
        }
        if(x>=k) ans += x-k+1;
    }
    if(k==1) return cout<<ans1<<endl, 0;
    for(int i=0; i<m; i++){
        x = 0;
        for(int j=0; j<n; j++){
            if(str[j][i]=='.')x++;
            else {
                if(x>=k) ans += x-k+1;
                x = 0;
            }
        }
        if(x>=k) ans += x-k+1;
    }
    cout<<ans<<endl;
}
