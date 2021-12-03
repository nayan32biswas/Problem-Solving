#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    long long x, y, one, Max;
    int cnt1, cnt2, i, j;

    cin>>cnt1>>cnt2>>x>>y;

    if(cnt1<cnt2){
        swap(cnt1, cnt2);
        swap(x, y);
    }

    for(i=1, one=1; ; i++){
        one = x*i;
        if(one-i>=cnt1){
            i--;
            while((one-i)!=cnt1)one++;
            break;
        }
    }
    Max = one;
    cnt2-=i;
    if(cnt2<=0) return printf("%lld\n", Max), 0;
    for(Max++; cnt2; Max++){
        if(Max%y!=0) cnt2--;
    }Max--;
    cout<<Max<<endl;
    return 0;
}
