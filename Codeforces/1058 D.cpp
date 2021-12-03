#include <bits/stdc++.h>
using namespace std;
long long p, n, m, k, g;
int main()
{
    cin>>n>>m>>k;
    bool even = !(k&1);
    if(even){
        k /= 2;
    }
    p = n*m;
    if(p%k != 0){
        puts("NO");
        return 0;
    }
    g = __gcd(n, k);
    k/=g;
    long long a = n/g;

    g = __gcd(m, k);
    k /= g;
    assert( k == 1);
    long long b = m / g;

    if(!even){
        if(a<n) a*=2;
        else assert(b<m), b*= 2;
    }
    puts("YES\n0 0");
    cout<<"0 "<<b<<endl;
    cout<<a<<" 0"<<endl;
    return 0;
}
