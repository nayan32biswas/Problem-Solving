#include <bits/stdc++.h>
using namespace std;
#define Size 21
int arr[Size], n, a, b;
int oposit(int x) {
    //cout<<x<<" ";
    int t = n-x-1;
    //cout<<t<<endl;
    return t;
}
bool isPalin() {
    for(int i=0, j=n-1; i<j; i++, j--) {
        if(arr[i]!=arr[j])
            return false;
    }
    return true;
}
int main() {
    cin>>n>>a>>b;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int Min;
    if(a<b) {
        Min = 0;
    } else
        Min = 1;
    int ans=0, x;
    for(int i=0; i<n; i++) {
        if(arr[i]==2) {
            if(i==(n/2) && (n&1))
                ans += min(a, b), arr[i]=Min;
            else {
                if(arr[oposit(i)]==0) {
                    ans += a, arr[i]=0;
                } else if(arr[oposit(i)]==1) {
                    ans += b, arr[i]=1;
                } else {
                    ans += min(a, b), arr[i]=Min;
                }
            }
        }
    }
    if(isPalin()) {
        cout<<ans<<endl;
    } else
        puts("-1");
    return 0;
}
