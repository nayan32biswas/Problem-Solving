#include <bits/stdc++.h>
using namespace std;
void genaret(map<string, bool>&keyWord);
map<string, int> Find(string str, map<string, bool>&keyWord);
int main() {
    freopen("labtest.cpp", "r", stdin);
    map<string, int> check;
    map<string, bool>keyWord;
    vector< map<string, int> >ans;
    genaret(keyWord);
    string str;
    while(getline(cin, str)) {
        ans.push_back(Find(str, keyWord));
    }
    int i=1;
    for(auto LINE : ans) {
        cout<<"In line "<<(i++)<<", there is "<<LINE.size()<<" keyword."<<endl;
        for(auto it : LINE) {
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
}
map<string, int> Find(string str, map<string, bool>&keyWord) {
    map<string, int>ans;
    string temp = "";
    for(auto it : str) {
        if(isalpha(it)) {
            temp += it;
        } else if(temp.size()>0) {
            if(keyWord[temp]==true) {
                ans[temp]++;
            }
            temp = "";
        }
    }
    if(keyWord[temp]==true) {
        ans[temp]++;
    }
    return ans;
}
void genaret(map<string, bool>&keyWord) {
    string KEYWORD[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    for(auto it : KEYWORD)
        keyWord[it] = true;
}
