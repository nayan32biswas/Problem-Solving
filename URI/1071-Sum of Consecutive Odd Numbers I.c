#include<stdio.h>
int main()
{
    int a,b,i,temp,sum=0;
    scanf("%d%d",&a,&b);
    if(a<b)
    {
        temp=b;
        b=a;
        a=temp;
    }
        for(i=b+1; i<a; i++){
            if(i%2==1 || i%2==-1)
               sum+=i;
        }
        printf("%d\n",sum);
    return 0;
}
