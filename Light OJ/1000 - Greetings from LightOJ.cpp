#include<stdio.h>
int main()
{
    int n,a,b,x,c=1;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        x=a+b;
        printf("Case %d: %d\n",c,x);
        c++;
    }
    return 0;
}
