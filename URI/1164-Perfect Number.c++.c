#include<stdio.h>
int main()
{
    int n,i,a,sum=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        for(i=0; i<a; i++){
            if((sum+=i)==a)
                printf("%d eh perfeito\n",a);
            else if((sum+=i)!=a)
                printf("%d nao eh perfeito\n",a);
        }
    }
    return 0;
}
