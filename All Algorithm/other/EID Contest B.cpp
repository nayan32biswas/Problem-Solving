#include<stdio.h>
int main()
{
    long long int n, m, a, ans, row,colum;
    scanf("%lld%lld%lld",&m, &n, &a);
    row = m/a;
    colum = n/a;
    if(m%a!=0)
        row++;
    if(n%a!=0)
        colum++;
    ans = row*colum;
    printf("%lld",ans);
    return 0;
}
