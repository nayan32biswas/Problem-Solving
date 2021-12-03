#include<stdio.h>
int main()
{
    int a[1000],i,n,k=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    int small=a[k];

    for(i=0; i<n; i++){
        if(a[i]<small){
            small=a[i];
            k=i;
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n",a[k],k);
    return 0;
}
