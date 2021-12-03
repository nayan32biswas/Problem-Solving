#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    long long n;
    int i, test;
    cin>>test;
    for(i=1; i<=test; i++){
        scanf("%lld", &n);
        printf("Case %d: %lld\n", i, (n>>1));
    }
    return 0;
}

