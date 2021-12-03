#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int arr[Size];
int main() {
    map<char, bool>Map;
    Map['a'] = 1;
    Map['e'] = 1;
    Map['i'] = 1;
    Map['o'] = 1;
    Map['u'] = 1;
    Map['y'] = 1;
    string str, ans;
    int n;
    cin>>n;
    cin>>str;
    ans+=str[0];
    for(int i=1; i<n; i++){
        if(!Map[ans[ans.size()-1]] || !Map[str[i]]){
            ans += str[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
