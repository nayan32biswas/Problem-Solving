#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n, test, dis=0;
    char s[20];
    cin>>test;
    while(test--){
        scanf("%d%s", &n, s);
        if(!dis && s[0]!='S'){
            cout<<"NO"<<endl;
            return 0;
        }
        if(dis==20000 && s[0]!='N'){
            cout<<"NO"<<endl;
            return 0;
        }
        if(s[0]=='S') dis+=n;
        if(s[0]=='N') dis-=n;
        if(dis<0 || dis>20000){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(dis==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
