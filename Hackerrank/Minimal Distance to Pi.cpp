#include <bits/stdc++.h>
#define pi 3.14159265359
#define lld long double
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    long long Min, value, value1, Max, i, ans_n=0, ans_d=0;
    while(cin>>Min>>Max){
        lld n, MIN=1.99999, temp;
        for(i=Max, Min--; i>Min; i--){
            value = (lld)((lld)pi*(lld)i);
            value1=value+1;
            n = ((pi)-((lld)value/(lld)i));
            temp = (((lld)value1/(lld)i)-(pi));
            if(n<temp){
                if(n<MIN) {
                    ans_n = value, ans_d = i, MIN=n;
                }
            }
            else {
                if(temp<MIN){
                    ans_n = value1, ans_d=i, MIN=temp;
                }
            }
        }
        printf("%lld/%lld\n", ans_n, ans_d);
    }
    return 0;
}
