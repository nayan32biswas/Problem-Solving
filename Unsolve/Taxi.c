#include<stdio.h>
int main()
{
    long int n,a,sum;
    scanf("%ld",&n);
    sum=0;
    while(n--){
        scanf("%ld",&a);
        sum=sum+a;
    }
    sum=((sum+3)/4);
    printf("%ld\n",sum);
    return 0;
}
