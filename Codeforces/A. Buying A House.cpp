#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k, Min=999999, x;
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++) {
        cin>>x;
        if(x<=k && x) {
            Min = min(Min, abs(i-m));
        }
    }
    cout<<Min*10<<endl;
    return 0;
}
