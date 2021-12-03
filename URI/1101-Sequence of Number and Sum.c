#include<stdio.h>
int main()
{
    int a,b,i,sum,temp;
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a>b){
            temp=a;
            a=b;
            b=temp;
        }
        if(a<=0 || b<=0)
            return 0;
            sum=0;
        for(i=a; i<=b; i++){
            printf("%d ",i);
            sum+=i;
        }
        printf("Sum=%d\n",sum);
    }
    return 0;
}
