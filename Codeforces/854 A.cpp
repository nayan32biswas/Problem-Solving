#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int main()
{
    int n, x, x1, ans=0, lo=0, hi=0, Min=999;
    cin>>n;
    x = n/2;
    if((x*2)==n) x--;
    x++;
    while(x--){
        x1 = __gcd(x, n-x);
        if(x1<Min){
            lo = x;
            hi = n-x;
            Min = x1;
        }
    }
    cout<<lo<<' '<<hi<<endl;
    return 0;
}
