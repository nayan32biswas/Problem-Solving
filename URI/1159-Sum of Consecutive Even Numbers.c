#include<stdio.h>
int main()
{
    int x,i,sum;
    for(;;){
        scanf("%d",&x);
        if(x==0)
            break;
        sum=0;
        for(i=x; i<x+10; i++){
            if(i%2==0)
                sum+=i;
        }
        printf("%d\n",sum);
    }
    return 0;
}
