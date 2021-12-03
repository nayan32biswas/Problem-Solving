#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n;
    long double x = sin(72*M_PI/180)/ sin(63*M_PI/180);
    while(scanf("%lf", &n)==1) {
        n  *= x;
        printf("%.10lf\n", n);
    }
    return 0;
}
