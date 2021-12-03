#include <bits/stdc++.h>
using namespace std;
int arr[100050], ans, Max, Min=9999999999;
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(Max<arr[i])Max=arr[i];
        if(Min>arr[i])Min=arr[i];
    }
    for(int i=0; i<n; i++){
        if(arr[i]<Max && arr[i]>Min)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
