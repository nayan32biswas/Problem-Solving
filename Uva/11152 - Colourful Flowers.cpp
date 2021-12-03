#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define fix fixed<<setprecision(4)
#define hulfParameterOfTriangle(a, b, c) (a+b+c)*0.5
#define areaOfCircle(r) (double)(r*r*pi)
#define areaOfTriangle(S, a, b, c) sqrt(S*(S-a)*(S-b)*(S-c))
#define outerCircleRadius(a, b, c) ((a*b*c)/(double)sqrt((a+b+c)*(a+b-c)*(a-b+c)*(-a+b+c)))
#define underCircleRadius(S, a, b, c) ((sqrt(S*(S-a)*(S-b)*(S-c)))/(double)S)
int main()
{
    double a, b, c;
    while(cin>>a>>b>>c){
        double A = hulfParameterOfTriangle(a, b, c);
        double S = areaOfTriangle(A, a, b, c);
        double r = underCircleRadius(A, a, b, c);
        double R = outerCircleRadius(a, b, c);
        double smallCircle = areaOfCircle(r);
        cout<<fix<<(areaOfCircle(R)-S)<<" "<<fix<<(S-smallCircle)<<" "<<fix<<(smallCircle)<<endl;
    }
    return 0;
}
