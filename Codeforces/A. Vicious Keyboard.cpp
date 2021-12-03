#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len=s.size(), i, ans=0;
    if(len==1) return puts("0"), 0;
    for(i=1; i<len; i++)if(s[i]=='K' && s[i-1]=='V'){
        s[i]='0', s[i-1]='0';
        ans++;
    }
    for(i=1; i<len; i++)if(s[i]!='0' && s[i-1]!='0'){
        if(s[i]==s[i-1]){ans++;break;}
    }
    cout<<ans<<endl;
}
