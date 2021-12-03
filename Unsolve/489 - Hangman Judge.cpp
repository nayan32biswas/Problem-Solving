#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int test, len, len1, i, finds[130], j;
    char ch[150], c[200];
    bool b;
    while(cin>>test){
        if(test<0) break;
        memset(finds,0,sizeof(finds));
        memset(ch,0,sizeof(ch));
        b=0;
        cin>>ch;
        len = strlen(ch);

        for(i=0; i<len; i++)
            finds[ch[i]]++;

        cin>>c;
        len1 = strlen(c);

        for(j=0; j<len1; j++){
            if(finds[c[i]]>0) finds[c[i]]=0;
            else len--;
            if(len==0){b=1; break;}
        }
        if(b==0 && len!=0) printf("Round %d\nYou win.\n", test);
        else if(len!=0) printf("Round %d\nYou chickened out.",test);
        else if(b==1)printf("Round %d\nYou lose.\n", test);
    }
    return 0;
}
