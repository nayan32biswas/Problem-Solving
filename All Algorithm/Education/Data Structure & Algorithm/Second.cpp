#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n<2) return false;
    if(n==2) return true;
    if(!(n&1)) return false;
    for(int i=3; i*i<=n; i+=2)
        if(n%i==0) return false;
    return true;
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(; n<=m; n++)
        if(isPrime(n)) printf("%d ", n);
    puts("");
    return 0;
}
