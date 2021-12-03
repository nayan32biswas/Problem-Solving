#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, ans, i, len;
    char s[2009];
    cin>>test;
    while(test--){
        bool ck;
        scanf("%s", s);
        len = strlen(s);
        for(i=0, ans=0; i<len; i++)if(s[i]=='1' && s[i+1]=='0'){
            i++;
            while(s[i]=='0') i++;
            if(s[i]=='1') ans++;
            i--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
