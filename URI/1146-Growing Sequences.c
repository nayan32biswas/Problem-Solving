#include<stdio.h>
int main()
{
    int x,i;
    while(scanf("%d",&x)!=EOF){
            if(x==0)
            break;
        for(i=1; i<=x; i++){
                if(i>=2)
                    printf(" ");
                printf("%d",i);
                if(i==x)
                    printf("\n");
        }
    }
    return 0;
}
