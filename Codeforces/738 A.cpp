#include <stdio.h>
char s[200];
int main()
{
    int len, i, J;
    scanf("%d%s", &len, s);
    for(i=0; i<len; i++){
        if(s[i]=='o' && s[i+1]=='g') {
            i++;
            while(s[i]=='g' && s[i+1]=='o') i+=2;
            printf("***");
            i--;
        }
        else printf("%c", s[i]);
    }
    return 0;
}
