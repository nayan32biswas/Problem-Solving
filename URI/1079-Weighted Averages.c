#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        float a,b,c,sum;
        scanf("%f%f%f",&a,&b,&c);
        sum=((a*2)+(b*3)+(c*5))/10;
        printf("%.1f\n",sum);
    }
    return 0;
}
