#include <bits/stdc++.h>
using namespace std;
#define pi 3.141592653589793238
#define incre 0.000000000001
bool check(double a, double b){
    if(abs(a-b)<(0.0000000001)) return true;
    return false;
}
double carcom(double r){ return 2*r*pi; }
double finde(double R, int n){
    double start = 0, End = R, mid, small, poridhi;
    int i=0;
    while(++i<500){
        mid = (start+End)/2;
        small = carcom(R-mid);
        poridhi = ((2*mid)*n);
        if(poridhi<small) start = mid+incre;
        else End = mid-incre;
        cout<<"start is: "<<start<<"  End is: "<<End<<"  mid is: "<<mid<<"  poridhi is: "<<poridhi<<" small is: "<<small<<endl;
        if(check(small, poridhi)==true) break;
    }
    return mid;
}
int main()
{
    freopen("input.txt", "r", stdin);
    double R;
    int test, n;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%lf%d", &R, &n);
        printf("Case %d: ", t);
        cout<<finde(R, n)<<endl;
    }
    return 0;
}
