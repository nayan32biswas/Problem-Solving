#include<stdio.h>
int main()
{
    int n,x,y,i,temp,sum;
    scanf("%d",&n);
    while(n--){
            sum=0;
        scanf("%d%d",&x,&y);
        if(x>y){
            temp=x;
            x=y;
            y=temp;
        }
        for(i=x+1; i<y; i++){
            if(i%2==1){
                sum+=i;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
