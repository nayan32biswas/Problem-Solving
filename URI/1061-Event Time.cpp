#include<stdio.h>
int main()
{
    int d,d1,h,h1,m,m1,n1,s,s1;
    int w,x,y,z;
    scanf("Dia %d %d : %d : %d\n",&d,&h,&m,&s);
    scanf("Dia %d %d : %d : %d",&d1,&h1,&m1,&s1);
    if(s==s1)
        z=0;
    else if(s>s1){
        z=60-s+s1;
        m++;
    }
    else
        z=s1-s;
    if(m==m1)
        y=0;
    else if(m>m1){
        y=60-m+m1;
        h++;
    }
    else
        y=m1-m;
    if(h==h1)
        x=0;
    else if(h>h1){
        x=24-h+h1;
        d++;
    }
    else
        x=h1-h;
    w=d1-d;

    printf("%d dia(s)\n",w);
    printf("%d hora(s)\n",x);
    printf("%d minuto(s)\n",y);
    printf("%d segundo(s)\n",z);
    return 0;
}
