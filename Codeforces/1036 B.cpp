#include <bits/stdc++.h>
using namespace std;
bool even(long long a) {
    return (!(a&1));
}
void solve() {
    long long ni, mi, k;
    cin>>ni>>mi>>k;
    if(max(ni, mi)>k)
        k = -1;
    else if(even(ni+mi)) {
        if(even(ni)) {
            if(!even(k))
                k -= 2;
        } else if(even(k))
            k -= 2;
    } else
        k--;
    cout<<k<<endl;
}
int main() {
    int q;
    cin>>q;
    while(q--)
        solve();
    return 0;
}
