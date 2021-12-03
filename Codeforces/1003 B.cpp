#include <bits/stdc++.h>
using namespace std;
string str;
string send(int t, char c){
    string te = "";
    while(t-->0)te+=c;
    return te;
}
int make(int x){
    x = (x+1)/2;
    for(int i=0; i<x; i++)str+= "10";
    return x;
}
int main()
{
    int a, b, x;
    cin>>a>>b>>x;
    int t = make(x);
    a -= t, b -= t;
    x = !(x&1);

    str = str + send(a, '0');
    str = send(b, '1')+str;
    if(x){
        int len = str.size();
        if(a>b){
            cout<<'0';
            for(int i=0; i<len-1; i++) cout<<str[i];
        }
        else{
            for(int i=1; i<len; i++) cout<<str[i];
            cout<<'1';
        }
    }
    else cout<<str<<endl;
}
