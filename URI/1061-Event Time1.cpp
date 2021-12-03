#include<stdio.h>
int main()
{
    char abc,bac,cab,abc1,bac1,cab1;
    int d,d1,h,h1,m,m1,n1,s,s1;
    long long int Ans,w,x,y,z,l;
    scanf("%s%d%d%s%d%s%d",&abc,&d,&h,&bac,&m,&cab,&s);
    scanf("%s%d%d%s%d%s%d",&abc1,&d1,&h1,&bac1,&m1,&cab1,&s1);
    Ans=(d1*86400+h1*3600+m1*60+s1)-(d*86400+h*3600+m*60+s);
    l=Ans%86400;
    w=Ans/86400;
    x=l/3600;
    y=(l%3600)/60;
    z=(l%3600)%60;
    printf("%lld dia(s)\n",w);
    printf("%lld hora(s)\n",x);
    printf("%lld minuto(s)\n",y);
    printf("%lld segundo(s)\n",z);
    return 0;
}

