#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int arr[Size];
int main()
{
    long long n, m, a, b;
    cin>>n>>m>>a>>b;
    long long lo = (n/m)*m;
    long long hi = (n/m+1)*m;
    cout<<min(abs(hi-n)*a, abs(lo-n)*b)<<endl;
    return 0;
}
