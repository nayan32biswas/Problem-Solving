#include <bits/stdc++.h>
using namespace std;
string to_lower(string str){
    string STRING="";
    for(int i=0; str[i]; i++){
        if(str[i]<'A' || str[i]>'z') continue;
        if(str[i]>'Z' && str[i]<'a') continue;
        if(str[i]<'a'){
            STRING += char(str[i]+32);
        }
        else{
            STRING += str[i];
        }
    }
    return STRING;
}
string GRUMPY[] = {
    "DON'T EVEN",
    "Are you serious?",
    "no way",
    "Go die in a hole",
    "Worse",
    "Terrible"
};
string NORMAL[] = {
    "great",
    "don't think so",
    "don't touch me",
    "not bad",
    "cool"
};
int main()
{
    freopen("input.txt", "r", stdin);
    map<string, bool>normal, grumpy;
    for(auto it : NORMAL){
        normal[to_lower(it)] = 1;
    }
    for(auto it : GRUMPY){
        grumpy[to_lower(it)] = 1;
    }
    bool check = true;
    string str;
    while(getline(cin, str)){
        if(grumpy[to_lower(str)]){
            check = false;
        }
    }
    if(check) puts("normal");
    else puts("grumpy");
    return 0;
}
