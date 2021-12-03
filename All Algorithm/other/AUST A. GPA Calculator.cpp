#include <stdio.h>
int main()
{
    double num, sum;
    int test, n, t, i;
    scanf("%d", &test);
    for(t=1; t<=test; t++){
        scanf("%d", &n);
        sum=0;
        for(i=0; i<n; i++){
            scanf("%lf", &num);
            sum+=num;
        }
        printf("Case %d: %.3lf\n",t, sum/n);
    }
    return 0;
}
