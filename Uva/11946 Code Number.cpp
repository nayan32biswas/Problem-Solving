#include <bits/stdc++.h>
using namespace std;
map<char, char>Map;
void bild() {
    Map['0'] = 'O';
    Map['1'] = 'I';
    Map['2'] = 'Z';
    Map['3'] = 'E';
    Map['4'] = 'A';
    Map['5'] = 'S';
    Map['6'] = 'G';
    Map['7'] = 'T';
    Map['8'] = 'B';
    Map['9'] = 'P';
}
int main() {
    //freopen("input.txt", "r", stdin);
    bild();
    int test;
    string str;
    cin>>test;
    cin.ignore();
    for(int t=0; t<test; t++){
        if(t) puts("");
        while(getline(cin, str) && str.size()>0){
            for(auto it : str){
                if(Map[it]) cout<<Map[it];
                else cout<<it;
            }
            puts("");
        }
    }
}
