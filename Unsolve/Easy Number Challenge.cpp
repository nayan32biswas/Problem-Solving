#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, i, j, k;
    long long sum, ans=0;
    cin>>a>>b>>c;
    for(i=1; i<=a; i++){
        for(j=1; j<=b; j++){
            for(k=1; k<=c; k++){
                if(i==a || j==b || k==b)
                    continue;
                ans+=(i+j+k);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
