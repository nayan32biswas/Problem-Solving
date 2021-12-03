#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, ans=0;
    cin>>n>>a>>b;
    if(a>b) swap(a, b);
    for(int i=2; i<n; i*=2){
        int inc = 1;
        ans++;
        while(inc<=n){
            if(a>=inc && b<inc+i){
                cout<<ans<<endl;
                return 0;
            }
            inc+=i;
        }
    }
    puts("Final!");
    return 0;
}
