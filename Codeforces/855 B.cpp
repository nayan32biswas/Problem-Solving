#include <bits/stdc++.h>
using namespace std;
#define MIN -(1e18*2)
int main()
{
    long long n, p, q, r, num;
    long long X[] = {MIN, MIN, MIN};
    cin>>n>>p>>q>>r;
    for(int i=0; i<n; i++){
        scanf("%lld", &num);
        X[0] = max(X[0], num*p);
        X[1] = max(X[1], num*q);
        X[2] = max(X[2], num*r);
    }
    num = X[0]+X[1]+X[2];
    cout<<num<<endl;
    return 0;
}

