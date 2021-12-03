#include <bits/stdc++.h>
using namespace std;
int p, q, r, s, t, u;
double finde(double x) {
    double temp;
    temp=((double)p*exp(-x))+((double)q*sin(x))+((double)r*cos(x))+((double)s*tan(x))+((double)t*x*x)+(double)u;
    return temp;
}
void solve() {
    double start=0, mid, End=1.000, temp;
    while(start<=End) {
        mid = (start+End)/2;
        temp = finde(mid);
        if(temp>(-0.000000001) && temp<(0.000000001)) break;
        if(temp>(0.000000001) || temp>(-0.000000001)) start= (mid+0.000000001);
        else End=(mid-0.000000001);
    }
    printf("%.4lf\n", mid);
}
int main() {
    //freopen("input.txt", "r", stdin);
    while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u)!=EOF) {
        if((finde(0.0)>0 && finde(1.0)>0.0) || (finde(0.0)<0.000 && finde(1.0)<0.00)) {
            puts("No solution");
        } else {
            solve();
        }
    }
}
