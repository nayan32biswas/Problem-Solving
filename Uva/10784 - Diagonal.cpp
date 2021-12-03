#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;
lli diagonals(lli n){
    n -= 3;
    return (n*2)+(n*(n-1)/2);
}
lli gon(lli n){
    if(n<=2) return 4;
    if(n<=5) return 5;
    lli start = 5, End, mid, num;
    if(n>1e9) End = 1e9;
    else End = n;
    while(start<=End){
        mid = (start+End)/2;
        num = diagonals(mid);
        if(num<n){
            start = mid+1;
        }
        else if(num>n){
            End = mid-1;
        }
        else break;
    }
    mid--;
    while(diagonals(mid)<n)mid++;
    return mid;
}
int main()
{
    lli N;
    int t = 0;
    while(scanf("%lld", &N) && N){
        printf("Case %d: %lld\n", ++t, gon(N));
    }
    return 0;
}
