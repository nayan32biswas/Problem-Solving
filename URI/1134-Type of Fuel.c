#include<stdio.h>
int main()
{
    int a[100],c[3]={0,0,0},i;
    for(;;){
        scanf("%d",&a[i]);
        if(a[i]==4)
            break;
        if(a[i]==1)
            c[0]++;
        if(a[i]==2)
            c[1]++;
        if(a[i]==3)
            c[2]++;
    }
    printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n",c[0],c[1],c[2]);
    return 0;
}
