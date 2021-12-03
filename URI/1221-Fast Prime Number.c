#include<stdio.h>
#include<math.h>
int main()
{
    int a,n,ch,i;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        ch=1;
        if(a==0 || a==1)
            printf("Not Prime\n");

        else{
            for(i=2; i<=sqrt(a); i++){
                if(a%i==0)
                    ch=0;
            }
            if(ch==1)
                printf("Prime\n");

            else
                printf("Not Prime\n");
        }
    }
    return 0;
}

