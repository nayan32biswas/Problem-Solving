#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull siriz(ull lo, ull hi){
    lo--; return ((hi*(hi+1))>>1)-((lo*(lo+1))>>1);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    long long test, n, m, neg, sum, i, temp1, temp2, ans;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%llu%llu", &n, &m);
        sum = siriz(m+1, m*2)-siriz(1, m);
        printf("Case %d: %llu\n", t, sum*(n/(m*2)));
    }
    return 0;
}
