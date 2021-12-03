#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    for(; b>0; a%=b, swap(a, b));
    return a;
}
int main()
{
    int n, m, z, i, x=0;
    cin>>n>>m>>z;
    x = z/((n*m)*gcd(n, m));
    cout<<x<<endl;
    return 0;
}
