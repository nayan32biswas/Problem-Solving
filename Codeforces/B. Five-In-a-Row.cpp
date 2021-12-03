#include <bits/stdc++.h>
using namespace std;
string S[]={"XXXXX", ".XXXX", "X.XXX", "XX.XX", "XXX.X", "XXXX."};
char str[11][11], c;
int SIZE=5;
bool win, ck;
void check(string s, string s1){
    for(int i=0; i<6; i++)if(S[i]==s || S[i]==s1){ win=true; break; }
}
void hori(int i, int j){
    int x;
    string temp="", temp1="";
    ck=false;
    if(i>0 && str[i-1][j]=='.') temp1+='.', ck=true;
    if(ck) for(x=i; x<(i+(SIZE-1)) && x<10; x++) temp1+=str[x][j];
    for(x=i; x<(i+SIZE) && x<10; x++) temp+=str[x][j];
    check(temp, temp1);

}
void ver(int i, int j){
    int x;
    string temp="", temp1="";
    ck=false;
    if(j>0 && str[i][j-1]=='.') temp1+='.', ck=true;
    if(ck) for(x=j; x<(j+(SIZE-1)) && x<10; x++) temp1+=str[i][x];
    for(x=j; x<(j+SIZE) && x<10; x++) temp+=str[i][x];
    check(temp, temp1);
}
void dia(int i, int j){
    int x, y;
    string temp="", temp1="";
    ck=false;
    if(i>0 && j>0 && str[i-1][j-1]=='.') temp1+='.', ck=true;
    if(ck) for(x=i, y=j; x<(i+(SIZE-1)) && x<10; x++, y++) temp1+=str[x][y];
    for(x=i, y=j; x<(i+SIZE) && x<10; x++, y++) temp+=str[x][y];
    check(temp, temp1);
}
void redia(int i, int j){
    int x, y;
    string temp="", temp1="";
    ck=false;
    if(i>0 && j>0 && str[i-1][j+1]=='.') temp1+='.', ck=true;
    if(ck) for(x=i, y=j; x<(i+(SIZE-1)) && x<10 && y>=0; x++, y--) temp1+=str[x][y];
    for(x=i, y=j; x<(i+SIZE) && x<10 && y>=0; x++, y--) temp+=str[x][y];
    check(temp, temp1);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    c='X';
    for(int i=0; i<10; i++)scanf("%s", str[i]);
    win = false;
    for(int i=0; i<10 && win==false; i++){
        for(int j=0; j<10 && win==false; j++)if(str[i][j]==c){
            hori(i, j);
            ver(i, j);
            dia(i, j);
            redia(i, j);
        }
    }
    if(win) puts("YES");
    else puts("NO");
}
