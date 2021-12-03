#include<stdio.h>
#include<string.h>
int main()
{
    char a[55];
    int n, i, j, len, sum = 0, sum1 = 0, c = 0;
    scanf("%d",&n);
    scanf("%s",a);
    for(i=0,j=n-1; i<n; i++,j--){
        if(i>j)
            break;
        if((a[i] == '4' || a[i] == '7') && (a[j] == '4' || a[j] == '7')){
            sum+=(a[i]-'0');
            sum1+=(a[j]-'0');
        }
        else{
            sum = 0;
            break;
        }
    }
    if((sum == sum1) && (sum > 0))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
