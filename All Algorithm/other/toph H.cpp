#include <bits/stdc++.h>
using namespace std;
int lo, hi, ans;
vector<long long>power;
void solve(){
    scanf("%d%d", &lo, &hi);
    ans=hi-lo+1;
    for(auto it : power){
        if(it>=lo && it<=hi) ans--;
    }
    printf("%d\n", ans);
}
int main()
{
    power.push_back(1);
    for(int i=1; i<32; i++){
        power.push_back(1LL<<i);
    }
    //for(auto it : power) cout<<it<<" "; puts("");
    int test;
    scanf("%d", &test);
    for(int i=0; i<test; i++){
        solve();
    }
}
