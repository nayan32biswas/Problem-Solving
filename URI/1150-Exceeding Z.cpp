#include<stdio.h>
int main()
{
    int x,z,i,count=0,sum=0;
    scanf("%d",&x);
    for(;;){
        scanf("%d",&z);
        if(x>=z)
            continue;
        else
            break;
    }
    for(i=x; i<=z; i++){
        sum=sum+i;
        count++;
        if(sum>=z)
            break;
    }
    printf("%d\n",count);
    return 0;
}
