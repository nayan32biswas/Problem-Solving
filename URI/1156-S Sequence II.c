#include<stdio.h>
int main()
{
    double i,S=0,j=1;
    for(i=1; i<=39; i+=2){
        S+=(i/j);
        j*=2;
    }
    printf("%.2lf\n",S);
    return 0;
}
