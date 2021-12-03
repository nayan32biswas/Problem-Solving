#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int len, n, k, i;
    cin>>n>>k>>s;
    len = s.size();
    bool b = false;
    for(i=0; i<len; i++){
        if(s[i]=='G' || s[i]=='T')
            break;
    }
    i+=k;
    for(;i<len; i+=k){
        if(s[i]=='T' || s[i]=='G'){
            b = true;
            break;
        }
        else if(s[i]=='#'){
            b=false;
            break;
        }
    }
    if(b==true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
