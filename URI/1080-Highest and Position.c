#include<stdio.h>
int main()
{
    int n,i,j=0,c;
    for(i=1; i<=100; i++){
        scanf("%d",&n);
        if(j<n){
            j=n;
            c=i;
        }
    }
    printf("%d\n%d\n",j,c);
    return 0;
}
