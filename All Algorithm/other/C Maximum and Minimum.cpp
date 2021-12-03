#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
long long Min, Max, many;
void string_to_int(char s[]) {
    int num, i, len, temp, J;
    len = strlen(s);
    for(i=len-1; i>=0; i--){
        if(s[i]>='0' && s[i]<='9'){
            num = 0, temp = 0, J = 0;
            while(s[i]>='0' && s[i]<='9'){
                temp = s[i]-48;
                temp =temp*pow(10, J);
                num+=temp;
                J++, i--;
            }
            i++, many++;
            if(num<Min) Min=num;
            if(num>Max) Max=num;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    char s[1000000];
    int test;
    scanf("%d\n", &test);
    for(int t=1; t<=test; t++){
        scanf("%[^\n]", s);
        Min = 10000000000000000, Max=0, many=0;
        string_to_int(s);
        printf("Case %d: Among %lld numbers %lld is maximum and %lld is minimum\n", t, many, Max, Min);
        getchar();
    }
    return 0;
}
