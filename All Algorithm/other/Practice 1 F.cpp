#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, int>Map;
    int n, x, ans=0;
    cin>>n;
    while(n--) scanf("%d", &x), Map[x]++;
    for(auto it : Map){
        if(it.first!=it.second){
            if(it.second<it.first) ans += it.second;
            else ans += it.second-it.first;
        }
    }
    cout<<ans<<endl;
}
