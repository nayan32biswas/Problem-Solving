#include <stdio.h>
#include <string.h>
char str[100009], sub[1009];

inline bool substring(int len) {
    int len0, len1, i, J;
    len1 = strlen(sub);
    if(len<len1) return false;
    len0 = (len-len1)+1;

    for(i=0; i<len0; i++){
        if(str[i]==sub[0]){
            for(J=1, i++; (J<len1 && str[i]==sub[J]); i++, J++);
            if(J==len1) return true;
        }
    }
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int test, n, len;
    scanf("%d", &test);
    for(int t=0; t<test; t++){
        scanf("%s%d", str, &n);
        len = strlen(str);
        for(int t1=0; t1<n; t1++){
            scanf("%s", sub);
            if(substring(len))puts("y");
            else puts("n");
        }
    }
    return 0;
}
