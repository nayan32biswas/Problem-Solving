#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define perimeter(a, b, c) ((a+b+c)*0.5)
#define triangleArea(a, b, c, S) sqrt(S*(S-a)*(S-b)*(S-c))
#define fix(n) fixed<<setprecision(n)
int main() {
    //freopen("input.txt", "r", stdin);
    double R1, R2, R3;
    double theta1, theta2, theta3;
    double A, B, C, S;

    int test;
    scanf("%d", &test);
    for(int t=1; t<=test; t++) {
        scanf("%lf%lf%lf", &R1, &R2, &R3);

        A = R2+R3;
        B = R1+R3;
        C = R1+R2;

        theta1 = acos((B*B+C*C-A*A)/(2*B*C));
        theta2 = acos((A*A+C*C-B*B)/(2*A*C));
        theta3 = acos((A*A+B*B-C*C)/(2*A*B));
        double area=triangleArea(A, B, C, perimeter(A, B, C));

        printf("Case %d: ", t);
        cout<<fix(10)<<(area)-((.5*R1*R1*theta1)+(.5*R2*R2*theta2)+(.5*R3*R3*theta3))<<endl;
    }
    return 0;
}
