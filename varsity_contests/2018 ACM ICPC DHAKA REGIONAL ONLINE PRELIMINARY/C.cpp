#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
lli perfectSque(lli l, lli r) {
    return (floor(sqrt(r)) - ceil(sqrt(l)) + 1);
}
int main() {
    freopen("input.txt", "r", stdin);
    lli l, r;
    int test;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%lld%lld", &l, &r);
        printf("Case %d: %lld\n", t, perfectSque(l, r));
    }
    return 0;
}
