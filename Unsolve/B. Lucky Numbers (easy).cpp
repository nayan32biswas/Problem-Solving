#include<stdio.h>
#include<string.h>
int main()
{
    int n, i, di, x, j, k;
    char a[50];
    di = 0; j = 0; k = 0;
    scanf("%s",a);
    n = strlen(a);
    for(i=0; i<n; i++)
        if(a[i] == '4' || a[i] == '7')
            di++;

    while(di>0){
        x = di % 10;
        di = di/ 10;
        if(x == 4 || x == 7)
            j++;
            k++;
    }
    if(j==k && j>0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
