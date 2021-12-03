#include<stdio.h>
#include<string.h>
int main()
{
    long long int N;
    int base[1000];
    int i, j, X;
    while(scanf("%lld",&N)!=EOF  && N >= 0){
        i = 0;
        while(N!=0){
            X = N % 3;
            base[i] = X;
            N = N / 3;
            i++;
        }
        if(i == 0)
            printf("0");
        for(j=i-1; j>=0; j--)
            printf("%d",base[j]);
        printf("\n");
    }
    return 0;
}
