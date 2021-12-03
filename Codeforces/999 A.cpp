#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int arr[Size];
int main()
{
    int n, k;
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>arr[i];
    int lo=0, hi = n-1;
    while(lo<=hi){
        if(arr[lo]<=k) lo++;
        else if(arr[hi]<=k) hi--;
        else break;
    }
    cout<<n-(hi-lo+1)<<endl;
    return 0;
}
