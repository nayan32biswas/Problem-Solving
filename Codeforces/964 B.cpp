#include <bits/stdc++.h>
using namespace std;
#define Size 1005
int main()
{
    int n, A, B, C, T, x, ans=0;
    cin>>n>>A>>B>>C>>T;
    if(B-C>=0) ans = n*A;
    else{
        for(int i=0; i<n; i++){
            cin>>x;
            ans += A-(T-x)*(B-C);
        }
    }
    cout<<ans<<endl;
    return 0;
}
