#include <bits/stdc++.h>
using namespace std;
int arr[105];
int main()
{
    freopen("input.txt", "r", stdin);
    int i, n, x=0;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]==0) x++;
    }
    if(x==n) return printf("%d\n", n), 0;
    for(i=n-1; i>=0; i--) if(arr[i]==1 && arr[i-1]==0) break;
    cout<<i<<endl;
}
