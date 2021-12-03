#include <bits/stdc++.h>
using namespace std;
int arr[130];
int main()
{
    int n, sum = 0, k, x, t;
    cin>>n>>k>>x;
    t = n-k;
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<t; i++) sum+=arr[i];
    for(int i=t; i<n; i++) sum+=min(arr[i], x);
    cout<<sum<<endl;
    return 0;
}
