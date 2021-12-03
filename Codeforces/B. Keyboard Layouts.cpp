#include<bits/stdc++.h>
using namespace std;
char arr[125];
char to_big(char c){
    return char(c-32);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    char s[30], s1[30], total[2000];
    scanf("%s%s", s, s1);
    int i;
    for(i=0; i<26; i++){
        arr[s[i]] = s1[i];
    }
    scanf("%s", total);


    int len=strlen(total);
    for(i=0; i<len; i++){
        if(total[i]>='a' && total[i]<='z'){
            printf("%c", arr[total[i]]);
        }
        else if(total[i]>='A' && total[i]<='Z'){
            char c = total[i]+32;
            printf("%c", to_big(arr[c]));
        }
        else printf("%c", total[i]);
    }
}
