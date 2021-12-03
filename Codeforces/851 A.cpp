#include <bits/stdc++.h>
using namespace std;
long long n, k, t;
int main()
{
    cin>>n>>k>>t;
    cout<<max((long long)0, (min(t, k)+min((long long)0, n-t)))<<endl;
    return 0;
}
