#include<stdio.h>
int main()
{
    int n,a,i,Mary,John;
    while(scanf("%d",&n)!=EOF){
        Mary=0;
        John=0;
        if(n==0)
            break;
        for(i=1; i<=n; i++){
            scanf("%d",&a);
            if(a==0)
                Mary++;
            else if(a==1)
                John++;
        }
        printf("Mary won %d times and John won %d times\n",Mary,John);
    }
    return 0;
}
