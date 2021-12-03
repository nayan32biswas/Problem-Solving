#include<stdio.h>
int main()
{
    int a,b,t,s;
    scanf("%d%d",&a,&b);
    if(a==b)
        t=24;
    if(a<b)
        t=b-a;
    else if(a>b){
        s=24-a;
        t=s+b;
    }
    printf("O JOGO DUROU %d HORA(S)\n",t);
    return 0;
}
