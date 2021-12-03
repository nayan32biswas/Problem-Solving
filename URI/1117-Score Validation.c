#include<stdio.h>
int main()
{
    float a,b,c=0,m;
    for(;;){
        scanf("%f",&a);
        if(a>=0 && a<=10){
            c++;

            for(;;){
            scanf("%f",&b);

            if(b>=0 && b<=10){
                    c++;
                    if(c==2)
                        break;
                }

                else
                    printf("nota invalida\n");
            }

        }
        else
            printf("nota invalida\n");

        if(c==2)
            break;
    }
    m=((a+b)/2);
    printf("media = %.2f\n",m);
    return 0;
}
