#include <bits/stdc++.h>
using namespace std;
int arr[100009];
int main() {
    int i, n, ans;
    cin>>n;

    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    ans = 0;
    for(i=0; i<n-1; i++){
        if((arr[i]&1)==(arr[i+1]&1)) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
