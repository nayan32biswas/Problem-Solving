#include<stdio.h>
int main()
{
    int x,y,i;
    while(scanf("%d%d",&x,&y)){
        if(x<y)
            printf("Crescente\n");
        else if(x>y)
            printf("Decrescente\n");
        else if(x==y)
            break;
    }
    return 0;
}
