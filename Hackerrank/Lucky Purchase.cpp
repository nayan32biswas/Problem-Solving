#include <bits/stdc++.h>
using namespace std;
map<long long, string>mark;
bool Check(long long n){
    int four=0, seven=0;
    while(n>0){
        if((n%10!=4 && n%10!=7) || (n<4 && n>1)) return false;
        if(n%10==4) four++;
        else seven++;
        n/=10;
    }
    if(four!=seven) return false;
    return true;
}
int main()
{
    string s;
    int test;
    long long n;
    cin>>test;
    while(test--){
        cin>>s>>n;
        if(Check(n))mark[n] = s;
    }
    if(mark.size()==0) puts("-1");
    else cout<<mark.begin()->second<<endl;
    return 0;
}
