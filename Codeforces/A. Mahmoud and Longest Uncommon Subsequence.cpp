#include <bits/stdc++.h>
#define SIZ 100010
using namespace std;
char s[SIZ], s1[SIZ];
int main()
{
    int ans=0, len, len1, i, J;
    bool ck=false;
    scanf("%s%s", s, s1);
    len = strlen(s);
    len1 = strlen(s1);
    if(len>len1 || len<len1){cout<<max(len, len1); return 0;}
    for(i=0; i<len && i<len1; i++) {
        if(s[i]!=s1[i]){
            cout<<max(len, len1)<<endl;
            return 0;
        }
    }
    puts("-1");
    return 0;
}
