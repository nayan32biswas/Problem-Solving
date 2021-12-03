#include<stdio.h>
int main()
{
    long int x,y,i;
    scanf("%ld%ld",&x,&y);
    for(i=1; i<=y; i++){
        printf("%ld",i);
        if(i%x!=0)
            printf(" ");
        if(i%x==0)
            printf("\n");
    }
    return 0;
}
