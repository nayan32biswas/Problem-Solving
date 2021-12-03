#include <bits/stdc++.h>
#define mod 100000
using namespace std;
bool ck;
string s;
int main()
{
    int test, temp, len, i, J;
    unsigned long long num;
    cin>>test;
    for(int t=1; t<=test; t++){
        ck=false;
        stack<int>S;
        cin>>s;
        len = s.size();
        for(i=0, num=0; i<len; i++){
            //if(s[i]==48)continue;
            num=(num*10)+(s[i]-48);
            if(num>mod)num%=mod;
        }
        //cout<<num<<endl;
        num %= mod;
        while(num>0){
            temp = num%10;
            num/=10;
            if(temp==0)continue;
            S.push(temp);
            ck=true;
        }
        while(!S.empty()){
            printf("%d", S.top());
            S.pop();
        }
        if(ck) cout<<endl;
    }
    return 0;
}
