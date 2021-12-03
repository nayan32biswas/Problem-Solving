#include <bits/stdc++.h>
using namespace std;
#define MAX 1e18
int main()
{
    long long x, y, X, Xmin, Y, Ymin, a, b;
    X = Y = -(MAX);
    Xmin = Ymin = MAX;
    int n;
    cin>>n;
    while(n--){
        scanf("%lld%lld", &x, &y);
        Xmin = min(x, Xmin);
        X = max(x, X);
        Ymin = min(y, Ymin);
        Y = max(y, Y);
    }
    unsigned long long M  = max(abs(Xmin-X), abs(Ymin-Y));

    cout<<(M*M)<<endl;
}
