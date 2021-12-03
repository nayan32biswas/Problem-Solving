#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans=INT_MAX;
    int n, a, b, c;
    cin>>n;
    for(int i=0; i<n; i++){
        scanf("%d%d%d", &a, &b, &c);
        ans = min(ans, max(a, b)+c);
    }
    cout<<ans<<endl;
}
