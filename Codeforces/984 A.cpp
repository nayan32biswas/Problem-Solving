#include <bits/stdc++.h>
using namespace std;
#define Size 1005
int arr[Size];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);
    cout<<arr[n/2]<<endl;
    return 0;
}
