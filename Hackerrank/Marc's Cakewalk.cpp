#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long X=0;
    int arr[50], n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);
    for(int i=0; i<n; i++){
        X += (pow(2, i)*arr[i]);
    }
    cout<<X<<endl;
    return 0;
}
