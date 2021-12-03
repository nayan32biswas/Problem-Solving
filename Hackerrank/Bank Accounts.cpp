#include <bits/stdc++.h>
using namespace std;
int main()
{
    double total, pi;
    int test, n, k, x, d;
    cin>>test;
    while(test--){
        scanf("%d%d%d%d", &n, &k, &x, &d);
        total = 0;
        while(n--){
            scanf("%lf", &pi);
            total += max((double)k, ((pi/(double)100)*(double)x));
        }
        if(total>d) puts("upfront");
        else puts("fee");
    }
}
