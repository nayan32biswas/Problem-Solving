#include<stdio.h>
int main()
{
    int n,i,x;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        for(i=x; i<=x; i++){
            if(i==0)
                printf("NULL\n");

            else if(i<0 && i%2==-1)
                printf("ODD NEGATIVE\n");

            else if(i<0 && i%2==0)
                printf("EVEN NEGATIVE\n");

            else if(i>0 && i%2==1)
                printf("ODD POSITIVE\n");

            else if(i>0 && i%2==0)
                printf("EVEN POSITIVE\n");
        }
    }
    return 0;
}
