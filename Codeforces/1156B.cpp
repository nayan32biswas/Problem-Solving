#include <bits/stdc++.h>
using namespace std;
void solve(){
    string str;
    vector<string>arr, ans;
    cin>>str;
    map<char, string>temp;
    for(auto it : str)temp[it]+=it;
    for(auto it : temp)arr.push_back(it.second);
    int len = arr.size();
    for(int i=0, j=len-1; i<j; i++, j--){
        ans.push_back(arr[j]);
        ans.push_back(arr[i]);
    }
    // for(auto it : ans)cout<<it;puts("");
    if(len&1) ans.push_back(arr[len/2]);
    // for(auto it : ans)cout<<it;puts("");
    if(len>1 && abs(ans[len-1][0]-ans[len-2][0])==1){
        ans.insert(ans.begin(), ans.back());
        ans.pop_back();
    }
    if(len>1 && abs(ans[0][0]-ans[1][0])==1){
        puts("No answer");
        return;
    }
    for(int i=0; i<len; i++)cout<<ans[i];puts("");
    // for(auto it : ans)cout<<it;puts("");
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for(int t=0; t<test; t++){
        solve();
    }
    return 0;
}