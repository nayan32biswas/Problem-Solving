#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    char s[1000];
    while(gets(s)){
        if(s[15]=='e'||s[16]=='t')
            printf("Byang\n");
        else
            printf("Byangette\n");
    }
    return 0;
}
