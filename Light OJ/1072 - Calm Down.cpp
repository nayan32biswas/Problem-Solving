#include <bits/stdc++.h>
using namespace std;
#define fix(n) fixed<<setprecesion(n)
#define PI acos(-1)
int main()
{
    int n, test;
    double R, temp;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%lf%d", &R, &n);
        printf("Case %d: %.7lf\n", t, sin(PI/n)*(R/(sin(PI/n)+1)));
    }
    return 0;
}
