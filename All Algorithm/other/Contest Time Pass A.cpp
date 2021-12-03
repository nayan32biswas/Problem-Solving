#include<stdio.h>
int main()
{
    int a,b,c,x,y;
    while(1){
        scanf("%d%d%d",&a,&b,&c);
        if(a==0&&b==0&&c==0)
            break;
        x=b-a;
        if(c==(x+b))
            printf("AP %d\n",x+c);
        else
            printf("GP %d\n",c*(b/a));
    }
    return 0;
}
