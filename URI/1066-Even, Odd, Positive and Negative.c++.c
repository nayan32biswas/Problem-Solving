#include<stdio.h>
int main()
{
    int a[5],b=0,c=0,d=0,e=0,i;
    for(i=0; i<5; i++){
        scanf("%d",&a[i]);
        if(a[i]%2==0)
            b++;
        if(a[i]%2!=0)
            c++;
        if(a[i]>0)
            d++;
        if(a[i]<0)
            e++;
    }
    printf("%d valor(es) par(es)\n",b);
    printf("%d valor(es) impar(es)\n",c);
    printf("%d valor(es) positivo(s)\n",d);
    printf("%d valor(es) negativo(s)\n",e);
    return 0;
}
