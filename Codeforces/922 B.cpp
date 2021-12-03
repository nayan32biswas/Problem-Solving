#include <bits/stdc++.h>
using namespace std;
bool is(int x, int y, int z){
    return x+y>z && x+z>y && z+y>x;
}
int main() {
    int n, ans=0, x, a, b, c;
    cin>>n;
    int t = clock();
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            x = i^j;
            if(x<=n && x<(i+j) && is(i, j, x) && x>=i && x>=j){
               ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

