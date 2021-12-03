#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long a = 1;
    long long b = 1;
    long long c = n-2;
    if(c%3==0) {
        c--;
        a++;
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
    return 0;
}
