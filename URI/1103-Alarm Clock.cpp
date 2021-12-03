#include <stdio.h>

int main()
{
    int h1,m1,h2,m2,t,t1;
    while(scanf("%d%d%d%d",&h1,&m1,&h2,&m2)!=EOF){
        if (h1==0&&m1==0&&h2==0&&m2==0)
            break;
        t=h1*60+m1;
        t1=h2*60+m2;
        if(t1>=t)
            printf("%d\n",t1-t);
        else
            printf("%d\n",(24*60-t)+t1);
    }
    return 0;
}
