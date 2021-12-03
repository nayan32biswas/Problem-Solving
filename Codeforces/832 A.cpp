
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k, num;
    cin>>n>>k;
    if(n==k) return puts("YES"), 0;
    num = n/k;
    if(num&1) puts("YES");
    else puts("NO");
}
