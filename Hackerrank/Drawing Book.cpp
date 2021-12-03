#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    //freopen("Input.txt", "r", stdin);
    int n, p, ans=0, temp;
    cin>>n>>p;
    if(n&1) n--;
    if(p&1) p--;
    if(p<=(n>>1)){
        cout<<(p>>1)<<endl;

    }
    else{
        for(; n>p; n-=2){
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
