#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans=0, i, n, k, x, sum=0, temp=0;
    cin>>n>>k;
    for(i=1; i<=n; i++){
        scanf("%d", &x);
        temp+=x;
        sum+=min(temp, 8);
        temp-=min(temp, 8);
        if(sum>=k) break;
    }
    if(i>n) puts("-1");
    else cout<<i<<endl;
}
