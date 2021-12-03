#include<stdio.h>
int main()
{
    long long int g,t,a,d,x,y,group,knockout,quater,semi,final;
    while(scanf("%lld%lld%lld%lld",&g,&t,&a,&d)!=EOF){
        if(g<0||t<0||a<0||d<0)
            break;
        group=((g*t)*(t-1))/2;
        knockout=(g*a)/2;
        quater=knockout/2;
        semi=quater/2;
        final=semi/2;
        y=d;
        if(d>0){
            knockout=(g*a);
            quater=knockout/2;
            semi=quater/2;
            final=(semi/2)+d;
            y=knockout-d;
        }
        x=group+knockout+quater+semi+final;
        printf("%lld*%lld/%lld+%lld=%lld+%lld\n",g,t,a,d,x,y);
    }
    return 0;
}
