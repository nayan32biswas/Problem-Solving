#include <bits/stdc++.h>
using namespace std;
char s[1000];
int main()
{
    //freopen("input.txt", "r", stdin);
    int len, i, J, sum;
    while(gets(s)){
        len = strlen(s);
        if(s[0]==0) {
            puts("");
            continue;
        }
        for(i=0; i<len; i++){
            sum=0;
            while(s[i]>='0' && s[i]<='9'){
                sum= sum + (s[i]-48);
                i++;
            }
            if(s[i]=='b'){
                for(J=0; J<sum; J++){
                    putchar(' ');
                }
            }
            else if(s[i]=='!') puts("");
            else{
                for(J=0; J<sum; J++){
                    putchar(s[i]);
                }
            }

            //cout<<sum<<endl;
        }
        puts("");
    }
    return 0;
}
