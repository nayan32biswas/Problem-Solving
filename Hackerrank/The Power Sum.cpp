#include <bits/stdc++.h>
using namespace std;
vector<int>power;
int way(int N, int pos){
    //cout<<N<<" "<<pos<<endl;
    if(N==0) return 1;
    int ans = 0;
    for(int i=pos; i<power.size(); i++){
        if(power[i]<=N){
            ans += way(N-power[i], i+1);
        }
    }
    return ans;
}
int PPP(int n, int p){
    int pp = 1;
    while(p--) pp *= n;
    return pp;
}
int main()
{
    int N, p;
    cin>>N>>p;
    for(int i=1; PPP(i, p)<=1000; i++) power.push_back(PPP(i, p));
    reverse(power.begin(), power.end());

    //for(auto it : power) cout<<it<<" "; puts("");

    cout<<way(N, 0)<<endl;
    return 0;
}
