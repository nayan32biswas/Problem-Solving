#include <bits/stdc++.h>
using namespace std;
int arr[101];
int main()
{
    int ans = 0, n, x;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        arr[x]++;
        ans = max(ans, arr[x]);
    }
    cout<<ans<<endl;
}
