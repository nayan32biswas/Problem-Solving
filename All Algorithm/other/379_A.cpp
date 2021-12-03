#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    char c;
    int n, a, d;
    bool b=0;
    while(cin>>n){
        getchar();
        a=0; d=0;
        for(int i=0; i<n; i++){
            scanf("%c",&c);
            if(c=='A') a++;
            else if(c=='D') d++;
        }
        if(a>d) cout<<"Anton"<<endl;
        else if(d>a) cout<<"Danik"<<endl;
        else if(a==d){cout<<"Friendship"<<endl; b=1;}
        //if(b==1) break;
    }
    return 0;
}
