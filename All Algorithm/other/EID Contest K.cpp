#include<stdio.h>
int main()
{
    int n, i, j;
    while(scanf("%d",&n)!=EOF){
        for(i=1; i<=n; i++){
            if((i == n) && (i%2 == 1))
                printf("I hate it");

            else if((i == n) && (i%2 == 0))
                printf("I love it");

            else if(i%2 == 1)
                printf("I hate that");

            else if(i%2 == 0)
                printf("I love that");

            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
