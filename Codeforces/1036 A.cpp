#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n, k;
    cin>>n>>k;
    long long ans = k/n;
    ans += !(k%n==0);
    cout<<ans<<endl;
    return 0;
}
