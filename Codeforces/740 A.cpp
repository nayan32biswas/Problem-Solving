#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c;
int main()
{
    cin>>n>>a>>b>>c;
    n = n%4;
    if(n==0) {
        puts("0"); return 0;
    }
    if(n==3)cout<<min(a, min(c*3, b+c));
    else if(n==2) cout<<min(b, min(c*2, 2*a));
    else if(n==1) cout<<min(c, min(a*3, a+b));
    return 0;
}
