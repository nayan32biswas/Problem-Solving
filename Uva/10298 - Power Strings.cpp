#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int ans, len;
string s;
bool check(string temp, int len1){
    int i, j;
    for(j=0, i=0, ans=0; i<len; i++, j++){
        if(j==len1) ans++, j=0;
        if(s[i]!=temp[j]) break;
    }
    if(i==len){ ans++; return true; }
    return false;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string temp;
    char c;
    bool ck;
    int i, j;
    while(cin>>s && s[0]!='.'){
        len = s.size();
        c = s[0];
        for(i=0; i<len && c==s[i]; i++);

        if(i==len) ans = len;
        else {
            ans = 1;
            temp.clear();
            temp+=s[0];
            for(i=1, ck=false; i<(len>>1) && !ck; i++){
                temp+=s[i];
                if(len%(i+1)==0){
                    ck = check(temp, i+1);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
