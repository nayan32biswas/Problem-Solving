#include<stdio.h>
int main()
{
    int n,i,j;
    double a[12][12],sum=0;
    char T;

    scanf("%d",&n);
    scanf("%s",&T);

    for(i=0; i<12; i++){
        for(j=0; j<12; j++){
            scanf("%lf",&a[i][j]);
            if(n==j)
                sum+=a[i][j];
        }
    }

    if(T=='S')
        printf("%.1lf\n",sum);
    else if(T=='W'){
        sum=sum/12;
        printf("%.1lf\n",sum);
    }

    return 0;
}
