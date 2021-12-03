#include<stdio.h>
int main()
{
    long int j,a,n,m,i,count,count1;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        for(i=1; i<=m; i++){
            scanf("%d",&a);
            if(a>m) count++;
            else if(a<m) count1++;
        }
            printf("Case %d: %d %d\n",n,count,count1);
    }
    return 0;
}
