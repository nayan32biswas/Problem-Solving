#include <bits/stdc++.h>
using namespace std;
#define Size 10005
int arr[Size];
bool is_true(int i){
    return (arr[i]>arr[i+1] && arr[i]>arr[i-1]) || (arr[i]<arr[i+1] && arr[i]<arr[i-1]);
}
int main(){
    int n, ans=0;
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    n--;
    for(int i=1; i<n; i++) if(is_true(i)) ans++;
    cout<<ans<<endl;
    return 0;
}
