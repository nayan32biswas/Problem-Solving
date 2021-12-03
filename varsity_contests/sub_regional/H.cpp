#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    long long n, k, x, ans=0;
    cin>>n>>k;
    if(n<=(k*2))
    {
        return 0*puts("10");
    }
    x = n/(k*3);
    if(x>0)
    {
        ans = x*15;
        x = n%(k*3);
        if(x>0)
        {
            if(x<=(k*2))
                ans+=10;
            else
                ans +=15;
        }
    }
    else
    {
        ans = 15;
    }
    cout<<ans<<endl;
    return 0;
}
