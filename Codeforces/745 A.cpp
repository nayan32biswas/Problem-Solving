#include <bits/stdc++.h>
using namespace std;
map<string, bool>M;
int ans = 1, len, i, J;
string s, s1;


int main()
{
    cin>>s;
    len = s.size();
    M[s]=1;
    for(i=1; i<=len; i++){
        s1.clear();
        for(J=i; J<len; J++){
            s1+=s[J];
        }
        for(J=0; J<i; J++){
            s1+=s[J];
        }
        if(M[s1]==0){
            M[s1]=1;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
