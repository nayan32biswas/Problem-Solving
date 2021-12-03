#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;
    cin>>str;
    vector<char>ope;
    for(auto it : str) {
        if(it!='?')
            ope.push_back(it);
    }
    reverse(ope.begin(), ope.end());
    vector<int>ans;
    int sum = 0, num = str.size()-ope.size();
    for(auto it : ope) {
        if(it=='-') {
            ans.push_back(1);
            sum += (-1);
        } else {
            if(sum<0) {
                ans.push_back(abs(sum));
                sum = 0;
            } else {
                ans.push_back(1);
                sum++;
            }
        }
    }
    if(sum==0) sum++;
    if(sum<0) ans.push_back(abs(sum));
    cout<<sum<<endl;
    if(sum>0){
        int i=0;
        for(auto it : ope){
            if(it=='-'){
                ans[i]+=sum;
            }
        }
    }
    reverse(ans.begin(), ans.end());

    for(auto it : ans){
        cout<<it<<endl;
    }
}
// -?+??
