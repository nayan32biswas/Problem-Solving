#include <bits/stdc++.h>
#define SIZ 100050
using namespace std;
string s[SIZ], temp;
int len[SIZ];
map<string, bool>M;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, i, J, line;
    long long ans;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>s[i];
        len[i] = s[i].size();
        M[s[i]]=true;
    }
    for(i=0; i<n; i++){
        line = len[i];
        if(line>1){
            temp.clear();
            for(J=0, line--; J<line; J++){
                temp = temp + s[i][J];
                M[temp]=false;
            }
        }
    }
    for(i=0, ans=0; i<n; i++) {
        if(M[s[i]]==true){
            line = len[i];
            for(J=0; J<line; J++){
                ans+=s[i][J];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
