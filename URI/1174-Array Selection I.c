#include<stdio.h>
int main()
{
    int i;
    float x;
    for(i=0; i<100; i++){
        scanf("%f",&x);
        if(x<=10)
        printf("A[%d] = %.1f\n",i,x);
    }
    return 0;
}
