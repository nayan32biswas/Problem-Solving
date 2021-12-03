#include <bits/stdc++.h>
using namespace std;
#define Size 500
void genaret(map<string, bool>&keyWord) {
    string KEYWORD[] = {
        "auto", "break", "bool", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    for(auto it : KEYWORD)
        keyWord[it] = true;
}
string commend(int line, string Commend[], int pos, string str) {
    int i;
    for(i=pos; i<str.size() && str[i]!='/'; i++);
    Commend[line] = "";
    for(; i<str.size(); i++) {
        Commend[line]+=str[i];
    }
}
vector<string> Find(int line, string Commend[], string str, map<string, bool>&keyWord) {
    vector<string>ans;
    string temp = "";
    char it;
    for(int i=0; i<str.size(); i++) {
        it = str[i];
        if(it=='/' && str[i+1]=='/') { ///////asldkjflas
            if(keyWord[temp]==true) {
                ans.push_back(temp);
            }
            commend(line, Commend, i, str);
            break;
        }
        if(isalpha(it)) {
            temp += it;
        } else if(temp.size()>0) {
            if(keyWord[temp]==true) {
                ans.push_back(temp);
            }
            temp = "";
        }
    }
    return ans;
}

int main() {
    freopen("Compiler Problem 2.cpp", "r", stdin); // ljasl////dkfjasldj lkasdjflkajs
    int line = 0;
    map<string, bool>keyWord;
    string Commend[Size];
    vector< vector<string> >ans;
    genaret(keyWord);
    string str;
    while(getline(cin, str)) {
        ans.push_back(Find(line, Commend, str, keyWord));
        line++;
    }
    for(int i=0; i<line; i++){
        if(Commend[i].size()>0 || ans[i].size()>0){
            printf("In line %d ", i+1);
            if(Commend[i].size()>0){
                cout<<"Commend is: "<<Commend[i]<<endl;
            }
            if(ans[i].size()>0){
                cout<<"keyword is: ";
                for(int j=0; j<ans[i].size(); j++){
                    cout<<ans[i][j]<<" ";
                }
                puts("");
            }
        }
    }
}
