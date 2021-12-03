#include <bits/stdc++.h>
using namespace std;
bool solve(){
    map<char, bool>M;
    M['a'] = 1, M['e'] = 1, M['i'] = 1, M['o'] = 1, M['u'] = 1;
    string str;
    cin>>str;
    int len = str.size()-1;
    char c = str[len];
    if(!M[c] && c!='n'){
        return 0;
    }
    for(int i=0; i<len; i++){
        if((!M[str[i]] && str[i]!='n') && !M[str[i+1]]) return 0;
    }
    return 1;
}
int main()
{
    puts(solve() ? "YES" : "NO");
    return 0;
}
