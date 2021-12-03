#include <bits/stdc++.h>
using namespace std;
#define Size 100
vector<string>input;
set<char>Set;
bool mark[Size];
int main() {
    char c;
    string str;
    while(cin>>str) {
        if(str[0]=='#')
            break;
        input.push_back(str);
        for(auto it : str)
            Set.insert(it);
    }
    int coun=Set.size();
    int pos = 0;
    while(coun>0) {
        for(auto it : input) {
            if(it.size()>pos && mark[it[pos]]==0) {
                cout<<it[pos];
                mark[it[pos]] = 1;
                coun--;
            }
        }
        pos++;
    }
    puts("");
    return 0;
}
