#include<stdio.h>
#include<string.h>
int main()
{
    char array[200];
    int ln,i,N;
    scanf("%d",&N);
    while(N--){
        scanf("%s",array);
        ln = strlen(array);
        if(ln>10)
            printf("%c%d%c\n",array[0],ln-2,array[ln-1]);
        else
            printf("%s\n",array);
    }
    return 0;
}
