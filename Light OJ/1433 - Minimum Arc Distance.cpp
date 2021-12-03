#include <bits/stdc++.h>
using namespace std;
#define fix(n) fixed<<setprecision(n)
double distance(double x, double y, double x1, double y1) {
    return sqrt( pow(abs(x-x1), 2) + pow(abs(y-y1), 2));
}
int main() {
    //freopen("input.txt", "r", stdin);
    double Ox, Oy, Ax, Ay, Bx, By, X, Y, theta, A, B, C;
    int test;
    scanf("%d", &test);
    for(int t=1; t<=test; t++) {
        cin>>Ox>>Oy>>Ax>>Ay>>Bx>>By;
        A = distance(Ox, Oy, Ax, Ay);
        B = distance(Ox, Oy, Bx, By);
        C = distance(Bx, By, Ax, Ay);
        theta = acos((pow(A, 2)+pow(B, 2)-pow(C, 2))/(2*A*B));
        cout<<"Case "<<t<<": "<<fix(5)<<theta*A<<endl;
    }
    return 0;
}
