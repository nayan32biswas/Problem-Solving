#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k;
    cin>>n>>k;
    if(k==0 || k==n) return puts("0 0"), 0;
    if(k*3<=n) return printf("1 %lld\n", k*2), 0;
    printf("1 %lld\n", n-k);
    return 0;
}

