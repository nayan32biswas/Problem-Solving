#include<stdio.h>
int main()
{
    long long int dm, i, j, x;
    char hdm[100];
    while(scanf("%lld", &dm)!=EOF){
        i=0;
        while(dm != 0){
            x = dm % 16;
            if(x<10)
                hdm[i] = x + 48; // I use ASCII value.
            else if(x>=10)
                hdm[i] = x -10 + 65; // I use ASCII value.

            dm = dm / 16;
            i++;
        }
        for(j=i-1; j>=0; j--)
            printf("%c",hdm[j]);
        printf("\n");
    }
    return 0;
}
