#include <bits/stdc++.h>
using namespace std;
vector<string>store;
string palin = "11";
int Size=2;
bool is_palin(string s){
    for(int i=0, j=s.size()-1; i<j; i++, j--){
        if(s[i]!=s[j]) return false;
    }
    return true;
}
int hi(int i){ return Size-i-1;}
long long to_int(string s){
    long long num=0;
    for(int i=0, len=s.size(); i<len; i++){
        num = (num*10)+(s[i]-48);
    }
    return num;
}
void incre(){
    for(int i=Size/2-1; ; i--){
        char c = palin[i];
        c = (c-48+1)%10;
        palin[i] = palin[hi(i)] = (c+48);
        if(c!=0) return;
        if(i==0){
            Size+=2;
            palin = '1'+palin+'1';
            return;
        }
    }
}
void Store(){
    store.push_back(palin);
    for(int i=0; i<100003; i++){
        incre();
        store.push_back(palin);
    }
    cout<<palin<<endl;
}
int main()
{
    Store();
    long long ans=0, x;
    int k, p;
    cin>>k>>p;
    for(int i=0; i<k; i++){
        x = to_int(store[i]);
        ans = (ans+x)%p;
    }
    cout<<ans%p<<endl;
    return 0;
}

