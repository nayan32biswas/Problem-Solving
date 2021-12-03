#include <bits/stdc++.h>
using namespace std;
string str;
vector<int>vec;
int n, a, b, ans;
void prepair() {
    int temp=0;
    for(auto it : str) {
        if(it=='*') {
            if(temp>0)
                vec.push_back(temp);
            temp = 0;
        } else {
            temp++;
        }
    }
    if(temp>0)
        vec.push_back(temp);
}
int main() {
    cin>>n>>a>>b>>str;
    prepair();
    int hulf;
    for(auto it : vec){
        hulf = it>>1;
        if(a){
            ans += min(hulf, a);
            a -= min(hulf, a);
        }
        if(b){
            ans += min(hulf, b);
            b -= min(hulf, b);
        }
        if(!a && !b) break;
        if(it&1){
            (a>b) ? a-- : b--;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
