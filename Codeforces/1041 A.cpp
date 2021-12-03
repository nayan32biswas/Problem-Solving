#include <bits/stdc++.h>
using namespace std;
#define Size 1005
int arr[Size];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    long long ans = 0;
    for(int i=1; i<n; i++){
        ans += arr[i]-arr[i-1]-1;
    }
    cout<<ans<<endl;
}
