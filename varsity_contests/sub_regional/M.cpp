#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,s1,ans;
    cin >> s;
    sort(s.begin(),s.end());
    while(true) {
            //cout << s << endl;
        char ch = s[s.size()-1];
        bool f = true;
        for(int i=s.size()-1; i>0; i--){
            if(s[i]=='z') continue;
            if(s[i]==s[i-1]) {
                f = false;
                break;
            }
        }
        if(f) break;
        else {
            char ch = s[s.size()-1];
            for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='z') ans += s[i];
            else {
                if(s1.size()==0 || s1[0]==s[i]) {
                    s1+= s[i];
                    if(s1.size()==2){
                        if(s1[0]=='z')
                            ans += 'z';
                    else
                        ans += s1[0]+1;
                        s1 = "";
                    }
                } else {
                    if(s1.size()==1) {
                        ans += s1[0];
                        s1 = "";
                    }
                    s1 += s[i];
                    }
                }
            }
            if(s1.size()==1) ans += s1[0];
        }
        s = "";
        for(int i=ans.size()-1; i>=0; i--) s += ans[i];
        ans = "";
        s1 = "";

    }
    sort(s.begin(),s.end());
    int len = s.size();
    for(int i=len-1; i>=0; i--) cout << s[i];
    cout << endl;
    return 0;
}
