#include <bits/stdc++.h>
using namespace std;
int Find(string s){
    map<char, bool>ck;
    int coun = 0;
    for(auto c : s){
        if(!ck[c]) coun++;
        ck[c] = 1;
    }
    return coun;
}
int main()
{
    int ans=0, n;
    string s, temp="";
    cin>>n>>s;
    for(auto c : s){
        if(c<91){
            ans = max(ans, Find(temp));
            temp = "";
        }
        else temp+=c;
    }
    ans = max(ans, Find(temp));
    cout<<ans<<endl;
}
