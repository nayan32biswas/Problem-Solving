#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    long double ans=0;
    int len = s.size();
    for(int i=0; i<len; i++){
        ans = (ans*10)+s[i]-'0';
        if(ans>(n-1))
            ans = fmod(ans,n);
    }
    if(ans>0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
