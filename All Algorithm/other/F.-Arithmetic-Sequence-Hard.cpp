#include<stdio.h>
int main()
{
    unsigned long long n, m, p, sum, i;
    scanf("%lld%lld",&n, &m);
    sum=(n*(n+1));
    sum=sum>>1;
    for(i=0; i<m; i++){
        scanf("%lld", &p);
        sum-=p;
    }
    printf("%lld\n", sum);

    return 0;
}
