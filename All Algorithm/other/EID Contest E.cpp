#include<stdio.h>
int main()
{
    long long int a[100000], n, k, i, j, x;
    scanf("%lld%lld",&n,&k);
        j=0;
        for(i=1; i<=n; i+=2){
            j++;
            if(j == k){
                printf("%lld\n",i);
                break;
            }
        }
        for(i=2; i<=k; i+=2){
            j++;
            if(j == k)
                printf("%lld\n",i);
        }
    return 0;
}
