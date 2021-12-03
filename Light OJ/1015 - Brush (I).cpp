#include<stdio.h>
int main()
{
    int n,m,a,c=1,sum;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        sum=0;
        while(m--){
            scanf("%d",&a);
        if(a<0)
            continue;
            sum+=a;
        }
        printf("Case %d: %d\n",c,sum);
        c++;
    }
    return 0;
}
