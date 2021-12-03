#include <bits/stdc++.h>
using namespace std;
int x, y;
map<int, vector<string> >ans;
int toint(string str) {
    int n=0;
    for(auto it : str)
        n = (n*10)+(it-48);
    return n;
}
string tostr(int n) {
    string str;
    while(n) {
        str += ((n%10)+48);
        n/=10;
    }
    reverse(str.begin(), str.end());
    return str;
}
void valid(int ttt) {
    int n = ttt*ttt;
    string str = tostr(n);
    int len = str.size();
    if(len&1) {
        str = "0"+str;
        len++;
    }
    string a="";
    for(int i=0; i<len; i++) {
        if(i==(len/2)) {
            x = toint(a);
            a = "";
        }
        a+=str[i];
    }
    y = toint(a);
    if(x+y==ttt) {
        ans[len].push_back(str);
    }
}
int main() {
    int n;
    ans[2].push_back("00"), ans[2].push_back("01");
    ans[4].push_back("0000"), ans[4].push_back("0001");
    ans[6].push_back("000000"), ans[6].push_back("000001");
    ans[8].push_back("00000000"), ans[8].push_back("00000001");
    for(int i=2; i<=10000; i++)
        valid(i);
    while(scanf("%d", &n)==1) {
        for(auto it : ans[n])
            cout<<it<<endl;
    }
}
