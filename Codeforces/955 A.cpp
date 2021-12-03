#include <bits/stdc++.h>
using namespace std;
#define fix(n) fixed<<setprecision(n)
double discount(double Cost){
    return (Cost/100)*80;
}
double cost(int buns, int C, int N){
    int x = buns/N;
    if(buns%N!=0) x++;
    buns = x;
    return double(x)*C;
}
int main()
{
    int hh, mm;
    int H, D, C, N;
    double ans = INT_MAX;
    cin>>hh>>mm;
    cin>>H>>D>>C>>N;
    if(hh>=20){
        cout<<fix(4)<<discount(cost(H, C, N))<<endl;
        return 0;
    }
    ans = cost(H, C, N);
    if(mm!=0){
        hh++;
        H += (60-mm)*D;
    }
    H += ((20-hh)*60*D);
    ans = min(ans, discount(cost(H, C, N)));
    cout<<fix(4)<<ans<<endl;
    return 0;
}

