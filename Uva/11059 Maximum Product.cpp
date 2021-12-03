#include <bits/stdc++.h>
using namespace std;
long long product(int SSS[], int lo, int hi) {
    long long prd = 1;
    for(int i=lo; i<=hi; i++)
        prd *= SSS[i];
    return prd;
}
long long Find(int SSS[], int lo, int hi) {
    hi = max(lo, hi);
    if(lo==hi) {
        return SSS[lo];
    }
    int left=-1, right=-1;
    int even = 0;
    for(int i=lo; i<=hi; i++) {
        if(SSS[i]<0) {
            if(left<0) {
                left = i;
            }
            right = i;
            even++;
        }
    }
    if(!(even&1)){
        return product(SSS, lo, hi);
    }
    return max(product(SSS, left+1, hi), product(SSS, lo, right-1));
}
int main() {
    //freopen("input.txt", "r", stdin);
    int N, SSS[200], test=0;
    while(scanf("%d", &N) == 1) {
        for(int i=0; i<N; i++) {
            scanf("%d", &SSS[i]);
        }
        long long ans = 0;
        printf("Case #%d: The maximum product is ", ++test);
        int lo=0;
        for(int i=0; i<N; i++) {
            if(SSS[i]==0) {
                ans = max(ans, Find(SSS, lo, i-1));
                lo = i+1;
            }
        }
        if(lo<N) {
            ans = max(ans, Find(SSS, lo, N-1));
        }
        cout<<ans<<".\n\n";
    }
    return 0;
}
