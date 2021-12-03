#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int i,n,x,sum;
    scanf("%d",&n);
    while(n--){
        sum=0;
        scanf("%s",a);
        x=strlen(a);
        for(i=0; i<x; i++){
            if(a[i]=='1')
                sum+=2;
            else if(a[i]=='7')
                sum+=3;
            else if(a[i]=='4')
                sum+=4;
            else if(a[i]=='2' || a[i]=='3' || a[i]=='5')
                sum+=5;
            else if(a[i]=='0' || a[i]=='6' || a[i]=='9')
                sum+=6;
            else if(a[i]=='8')
                sum+=7;
        }
        printf("%d leds\n",sum);
    }
    return 0;
}
