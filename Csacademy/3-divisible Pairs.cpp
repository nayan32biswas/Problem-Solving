#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long ans, n, x, one=0, two=0, zero=0;
    cin>>n;
    while(n--){
        scanf("%lld", &x);
        if(x%3==0) zero++;
        else if(x%3==1) one++;
        else two++;
    }
    cout<<((one*two)+(zero*(zero-1))/2)<<endl;;
}
