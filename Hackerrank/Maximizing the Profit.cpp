#include <bits/stdc++.h>

using namespace std;
#define Size 200005
long long arr[Size];
int main() {
    int N;
    cin>>N;
    for(int i=0; i<N; i++) {
        scanf("%lld", &arr[i]);
    }
    long long ans = -9999999999999999;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int k=j+1; k<N; k++) {
                if(arr[i]<arr[j] && arr[j]<arr[k]) {
                    ans = max(ans, arr[i]*arr[j]*arr[k]);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
