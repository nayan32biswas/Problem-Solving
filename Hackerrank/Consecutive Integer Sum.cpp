#include <bits/stdc++.h>
using namespace std;
int serise(long long n) {
    return (n*(n+1))/2;
}
int range(int lo, int hi) {
    if(lo<1)
        return serise(hi);
    return (serise(hi)-serise(lo));
}
int n;
bool Find(int End, int len) {
    int start = 0, sum, mid;
    while(start<=End) {
        mid = (start+End)/2;
        if((mid-len)<0) {
            start=mid+1;
            continue;
        }
        sum = range(mid-len, mid);
        if(sum==n) {
            return true;
        }
        if(sum<n)
            start = mid+1;
        else
            End = mid-1;
    }
    return false;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
    for(int t=1; t<=test; t++) {
        cin>>n;
        int ans = 0;
        for(int i=2; i<n; i++) {
            if(Find(n, i))
                ans++;
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
