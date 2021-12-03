#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool isChar(char c){
    if(c>='A' && c<='Z') return true;
    return false;
}
bool isNum(char c){
    if(c>='0' && c<='9') return true;
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    char s[90], c;
    int num, len, test, i;

    double ans, stor[100];
    stor['C']=12.01, stor['H']=1.008;
    stor['O']=16.00, stor['N']=14.01;

    scanf("%d", &test);
    while(test--){
        scanf("%s", s);
        len = strlen(s);

        for(i=0, ans=0; i<len; i++){
            if((isChar(s[i]) && isChar(s[i+1])) || (isChar(s[i]) && !s[i+1])){
                ans+=stor[s[i]];
            }
            else if(isChar(s[i]) && isNum(s[i+1])){
                c = s[i++];
                num = s[i]-'0';
                if(isNum(s[i+1])){
                    i++;
                    num=(num*10)+(s[i]-'0');
                }
                ans+=(stor[c]*num);
            }
        }
        printf("%.3lf\n", ans);
    }
}
