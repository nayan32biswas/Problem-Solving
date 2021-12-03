#include <bits/stdc++.h>
using namespace std;

vector<string>str, Left, Right;
map<string, char>MAP;
void store(){
    for(int i=0; i<16; i++){
        int n = i;
        string temp = "";
        while(n){
            if(n&1) temp+='o';
            else temp+=' ';
            n>>=1;
        }
        if(i<=7){
            while(temp.size()<3) temp+=' ';
            reverse(temp.begin(), temp.end());
            Right.push_back(temp);
            Left.push_back("  "+temp);
        }
        else {
            while(temp.size()<5) temp+=' ';
            reverse(temp.begin(), temp.end());
            Left.push_back(temp);
        }
    }
    int i=0;
    for(auto it : Left){
        for(auto it1 : Right){
            MAP[(it+'.'+it1)] = (char)i++;
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    store();
    string ss, s;
    getline(cin, ss);
    while(getline(cin, ss) && ss != "___________"){
        s = "";
        for(auto c : ss)if(c!='|')s+=c;
        str.push_back(s);
    }
    for(auto it : str) cout<<MAP[it];

    return 0;
}

