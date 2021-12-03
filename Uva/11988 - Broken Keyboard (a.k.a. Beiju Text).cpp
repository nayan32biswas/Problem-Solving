#include <bits/stdc++.h>
using namespace std;
#define Size 1000000
list<string>ans;
bool check(char c){
    return (c>96 && c<123) || (c>64 && c<91) || c=='_';
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string s, prev, next;
    bool ck;
    while(cin>>s){
        ans.clear();
        prev.clear();
        next.clear();
        ck = false;
        for(int i=0; s[i]; i++){
            if(s[i]=='['){
                i++;
                if(next[0])ans.push_back(next);
                next.clear();
                prev.clear();
                for(; s[i] && check(s[i]); i++){
                    prev+=s[i];
                }
                i--;
                ans.push_front(prev);
            }
            else if(check(s[i]))next+=s[i];
        }
        if(next[0])ans.push_back(next);
        for(auto a : ans)cout<<a;
        puts("");
    }
}
