#include <bits/stdc++.h>
using namespace std;
#define Size 100005
long long arr[Size];
int main() {
    int test, N;
    scanf("%d", &test);
    while(test--) {
        scanf("%d", &N);
        int five=0, even=0, zero=0;
        long long ans=0;
        for(int i=0; i<N; i++) {
            scanf("%lld", &arr[i]);
            arr[i] = arr[i]%10;
            if(arr[i]%2==0) {
                even++;
                if(arr[i]==0)
                    zero++;
            } else if(arr[i]==5){
                five++;
            }
        }
        for(int i=0; i<N; i++) {
            if(arr[i]==0) {
                ans += N-i-1;
                even--;
                zero--;
            } else if(arr[i]%2==0) {
                even--;
                ans += five;
                ans += zero;
            } else if(arr[i]==5) {
                ans += even;
                five--;
            } else {
                ans += zero;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
