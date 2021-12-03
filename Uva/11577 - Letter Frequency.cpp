#include <stdio.h>
#include <string.h>
int main()
{
    char s[209], ch;
    int Max, test, arr[130], i, len, temp;
    scanf("%d\n", &test);
    while(test--){
        gets(s);
        len = strlen(s);
        memset(arr, 0, sizeof(arr));
        Max = 0;
        for(i=0; i<len; i++) {
            ch = s[i];
            if(ch<123 && ch>96){
                temp = ++arr[ch];
                if(Max<temp) Max = temp;
            }
            else if(ch<91 && ch>64){
                temp = ++arr[ch+32];
                if(Max<temp) Max = temp;
            }
        }
        for(i=97; i<123; i++){
            if(arr[i]==Max)printf("%c", i);
        }
        puts("");
    }
}
