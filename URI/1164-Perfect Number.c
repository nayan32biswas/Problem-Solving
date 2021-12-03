#include<stdio.h>
int main()
{
    int a[100],n,x,i,s;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        s=0;
        for(i=1; i<x; i++){
                s+=i;
            if(s==x)
                break;
        }
        if(s==x)
            printf("%d eh perfeito\n",x);
        else
         printf("%d nao eh perfeito\n",x);
    }
    return 0;
}
