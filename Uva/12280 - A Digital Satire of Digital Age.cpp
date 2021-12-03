#include <bits/stdc++.h>
using namespace std;
void left(string l, string r);
void right(string l, string r);
void Equal(string l, string r);
int equation(int num){
    int value = 0;
    while(num>0){
        if(num&1) value+=500;
        else value+=250;
        num>>=1;
    }
    return value;
}
int Find(string l, string r){
    int first = 0, second = 0;
    for(auto c : l) first+=equation(c);
    for(auto c : r) second+=equation(c);
    return first-second;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
    for(int t=1; t<=test; t++){
        printf("Case %d:\n", t);
        string str[7], l, r;
        for(int i=0; i<7; i++)cin>>str[i];
        cin>>l;
        l = "", r = "";
        if(str[6][1]>='_'){
            for(int i=1, pos=5; (str[pos][i]>='A' && str[pos][i]<='Z'); i++)l+=str[pos][i];
            for(int i=11, pos=3; (str[pos][i]>='A' && str[pos][i]<='Z'); i++)r+=str[pos][i];
            int x = Find(l, r);
            if(x>0) puts("The figure is correct.");
            else if(x==0) Equal(l, r);
            else right(l, r);
        }
        else if(str[4][1]>='_'){
            for(int i=1, pos=3; (str[pos][i]>='A' && str[pos][i]<='Z'); i++)l+=str[pos][i];
            for(int i=11, pos=5; (str[pos][i]>='A' && str[pos][i]<='Z'); i++)r+=str[pos][i];
            int x = Find(l, r);
            if(x<0) puts("The figure is correct.");
            else if(x==0) Equal(l, r);
            else left(l, r);
        }
        else {
            for(int i=1, pos=4; (str[pos][i]>='A' && str[pos][i]<='Z'); i++)l+=str[pos][i];
            for(int i=11, pos=4; (str[pos][i]>='A' && str[pos][i]<='Z'); i++)r+=str[pos][i];
            int x = Find(l, r);
            if(x==0)puts("The figure is correct.");
            else if(x<0) right(l, r);
            else left(l, r);

        }
    }
    return 0;
}
void left(string l, string r){
    string str[]={
    "........||.../\\...",
    "........||../..\\..",
    ".../\\...||./....\\.",
    "../..\\..||/......\\",
    "./....\\.||\\______/",
    "/......\\||........",
    "\\______/||........",
    };
    int i=1; for(auto c : l) str[5][i++] = c;
    i = 11; for(auto c : r) str[3][i++] = c;
    for(auto s : str) cout<<s<<endl;
}
void right(string l, string r){
    string str[]={
    ".../\\...||........",
    "../..\\..||........",
    "./....\\.||.../\\...",
    "/......\\||../..\\..",
    "\\______/||./....\\.",
    "........||/......\\",
    "........||\\______/",
    };
    int i = 1; for(auto c : l) str[3][i++] = c;
    i=11; for(auto c : r) str[5][i++] = c;
    for(auto s : str) cout<<s<<endl;
}

void Equal(string l, string r){
    string str[]={
    "........||........",
    ".../\\...||.../\\...",
    "../..\\..||../..\\..",
    "./....\\.||./....\\.",
    "/......\\||/......\\",
    "\\______/||\\______/",
    "........||........",
    };
    int i = 1; for(auto c : l) str[4][i++] = c;
    i=11; for(auto c : r) str[4][i++] = c;
    for(auto s : str) cout<<s<<endl;
}
