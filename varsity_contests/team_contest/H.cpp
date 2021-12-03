#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long ull;
using namespace std;
#define pi acos(-1)
void solve()
{
    double a, n;
    cin>>n>>a;
    // n = 8, a=2;
    double R = (a/2)*(1/sin(pi/n));
    printf("%.8lf\n", (R*pi*R));
}
int main()
{
    solve();
    return 0;
}