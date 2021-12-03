#include <bits/stdc++.h>
using namespace std;
long long n, upOne, dualZero, oneZero, zeroOne;

int main() {
    string a, b;
    cin>>n>>a>>b;
    for(int i=0; i<n; i++) {
        if(a[i]=='1') upOne++;
        if(a[i]=='0' && b[i]=='0')
            dualZero++;
        if(a[i]=='0' && b[i]=='1') zeroOne++;
        if(a[i]=='1' && b[i]=='0') oneZero++;
    }
    long long ans = dualZero*upOne;
    ans += zeroOne * oneZero;
    cout<<ans<<endl;
}
