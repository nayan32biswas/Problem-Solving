#include<stdio.h>
int main()
{
    double r,x,y,sum,pi=3.1415926535897932384626433832795;
    int c=1,n;
    scanf("%d",&n);
    while(n--){
        scanf("%lf",&r);
        x=4*r*r;
        y=pi*r*r;
        sum=x-y;
        printf("Case %d: %.2lf\n",c,sum);
        c++;
    }
    return 0;
}
