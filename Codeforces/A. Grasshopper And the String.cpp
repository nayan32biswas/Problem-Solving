#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    char str[10000];
    int cou, i, Max, len;
    while(scanf("%s",str)!=EOF){
        len = strlen(str);
        str[len]='\n';
        cou = Max = 0;
        for(i=0; i<=len; i++){
            cou++;
            if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='Y'||str[i]=='\n'){
                if(cou>Max) Max=cou;
                cou=0;
            }
        }
        printf("%d\n",Max);
    }
}
