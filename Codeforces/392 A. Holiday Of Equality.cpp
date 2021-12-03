#include <iostream>
using namespace std;
int main()
{
    int arr[200], Max=0, ans=0, n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]>Max)
            Max=arr[i];
    }
    for(int i=0; i<n; i++){
        ans+=(Max-arr[i]);
    }
    cout<<ans<<endl;
    return 0;
}
