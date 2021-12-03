#include<stdio.h>
int main()
{
    int i,a,b,c;
    for(i=1; i<=9; i+=2){
        a=i+6;
        printf("I=%d J=%d\n",i,a);
        b=i+5;
        printf("I=%d J=%d\n",i,b);
        c=i+4;
        printf("I=%d J=%d\n",i,c);
    }
    return 0;
}

