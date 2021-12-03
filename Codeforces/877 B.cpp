#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i, j, len = s.size(), ans=0;
    for(int i=0; i<len; i++){
        if(i<len-1 && (s[i]=='a' && s[i+1]=='b') || (s[i]=='b' && s[i+1]=='a')){
            ans++;
            i++;
        }
    }
    cout<<ans*2<<endl;

    return 0;
}

