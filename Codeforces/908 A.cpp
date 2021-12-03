#include <bits/stdc++.h>
using namespace std;
bool is(char ch){
    if(ch>='0' && ch<='9') return (ch&1);
    string vowel = "aeiou";
    for(auto it : vowel) if(it==ch) return true;
    return false;
}
int main()
{
    string str;
    cin>>str;
    int ans = 0;
    for(auto it : str) if(is(it)) ans++;
    cout<<ans<<endl;
}
