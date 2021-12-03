#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    string s, s1;
    char c;
    int i;
    bool ck;
    while(cin>>c>>s){
        if(c=='0' && s[0]=='0') return 0;
        ck = false;
        for(i=0; s[i]; i++){
            if(s[i]!=c && s[i]!='0') {
                printf("%c",s[i]);
                ck=true;
            }
        }
        if(ck==false) puts("0");
        else puts("");
    }
    return 0;
}
