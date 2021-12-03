#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10], n, m, x;
    map<int, bool>Map;
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<m; i++) cin>>x, Map[x] = true;
    for(int i=0; i<n; i++){
        if(Map[arr[i]]) cout<<arr[i]<<" ";
    }

    return 0;
}
