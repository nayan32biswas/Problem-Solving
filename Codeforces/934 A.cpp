#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, m, x, ans=(-1000000000000000000);
    long long Max = ans;
    cin>>n>>m;
    vector<long long>NNN, MMM;
    for(int i=0; i<n; i++){
        cin>>x;
        NNN.push_back(x);
    }
    for(int i=0; i<m; i++){
        cin>>x;
        MMM.push_back(x);
    }
    sort(NNN.begin(), NNN.end());
    for(int i=1; i<NNN.size(); i++){
        for(auto it : MMM) {
            ans = max(ans, NNN[i]*it);
        }
    }
    NNN.pop_back();
    for(auto it : NNN){
        for(auto it1 : MMM){
            Max = max(Max, it*it1);
        }
    }
    cout<<min(ans, Max)<<endl;
    return 0;
}
/*
4 4
1 2 3 4
-2 -3 -4 -6
*/
