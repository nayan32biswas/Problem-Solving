#include <bits/stdc++.h>
using namespace std;
set<string>SET;
string lower(string x){
    for(int i=0; x[i]; i++)
        if(x[i]<97) x[i]+=32;
    return x;
}
string s;
int main() {
    //freopen("input.txt", "r", stdin);
    while(getline(cin, s)) {
        string temp = "";
        for(auto c : s) {
            if((c>='A' && c<='Z') || (c>='a' && c<='z'))temp+=c;
            else {
                if(temp.size()>0) {
                    SET.insert(lower(temp));
                }
                temp.clear();
            }
        }
        if(temp.size())SET.insert(lower(temp));
    }
    for(auto a : SET)
        cout<<a<<endl;
    return 0;
}
