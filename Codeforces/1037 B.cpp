#include <bits/stdc++.h>
using namespace std;
#define Size 200000
long long arr[Size];
int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    for(int i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    long long ans = 0;
    sort(arr, arr+n);
    for(int i=n/2; i<n && arr[i]<s; i++) {
        if(arr[i]<s) {
            ans += abs(s-arr[i]);
        }
    }
    if(ans==0) {
        n=n/2;
        //cout<<n<<endl;
        for(int i=0; i<=n; i++) {
            if(arr[i]>s) {
                ans += abs(s-arr[i]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
