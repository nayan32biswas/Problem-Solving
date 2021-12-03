#include <bits/stdc++.h>
using namespace std;
#define Size 105
string strArray[Size];
bool clean(string str) {
    for(auto it : str) {
        if(it!=' ')
            return false;
    }
    return true;
}
void print(int len) {
    for(auto it : strArray) {
        if(!clean(it)) {
            for(int i=it.size()-1; i>=0; i--){
                if(it[i]!=' ') break;
                it.pop_back();
            }
            cout<<"| "<<it<<endl;
        }
    }
    printf("+--");
    while(len--)
        printf("-");
    puts("");
}
void addSpace(int maxLen) {
    int len = Size;
    for(int i=0; i<len; i++) {
        while(strArray[i].size()<maxLen)
            strArray[i]+=" ";
    }
}
void add(char c, int &pos) {
    strArray[pos] += c;
    addSpace(strArray[pos].size());
}
void solve() {
    map<char, char>M;
    M['C'] = '_', M['R'] = '/', M['F'] = '\\';
    string str;
    char prev = ' ';
    cin>>str;
    int pos = 50;
    for(int i=0; i<Size; i++)strArray[i].clear();
    for(auto it : str) {
        if((prev=='/' && M[it]=='_') || (prev=='/' && M[it]=='/'))pos--;
        else if((prev=='\\' && M[it]=='\\') || (prev=='_' && M[it]=='\\'))pos++;
        add(M[it], pos);
        prev = M[it];
    }
    print(str.size());
}
int main() {
    //freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for(int t=1; t<=test; t++) {
        printf("Case #%d:\n", t);
        solve();
        puts("");
    }
}
