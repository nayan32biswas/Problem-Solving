#include<stdio.h>
int main()
{
    double n,x,y,sum;
    scanf("%lf",&n);
    while(n--){
        scanf("%lf%lf",&x,&y);
        if(y==0)
            printf("divisao impossivel");
        else{
            sum=x/y;
            printf("%.1lf\n",sum);
        }
    }
    return 0;
}
