#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int test, a, b, c, d, e, x;
    char ch;
    while(cin>>test){
        if(test==0) return 0;
        for(int i=0; i<test; i++){
            cin>>a>>b>>c>>d>>e;
            x =  0;
            if(a<128){x++, ch='A';}
            if(b<128){x++, ch='B';}
            if(c<128){x++, ch='C';}
            if(d<128){x++, ch='D';}
            if(e<128){x++, ch='E';}
            if(x==1) cout<<ch<<endl;
            else puts("*");
        }
    }
    return 0;
}
