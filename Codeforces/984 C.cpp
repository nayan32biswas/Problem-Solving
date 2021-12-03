#include <bits/stdc++.h>
using namespace std;
bool isFinite(long long p, long long q, long long b){

    return true;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    long long p, q, b;
    scanf("%d", &n);
    while(n--){
        scanf("%lld%lld%lld", &p, &q, &b);
        //printf("%lld %lld %lld\n", p, q, b);
        if(isFinite(p, q, b)){
            puts("Finite");
        }
        else{
            puts("Infinite");
        }
    }
    return 0;
}
