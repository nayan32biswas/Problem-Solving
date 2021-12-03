#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char arr[10000];
    long long int sum, i, j, len;
    while(scanf("%s",arr)!=EOF){
        len = strlen(arr);
        sum = 0;
        if(arr[0] == '0' && len == 1)
            break;
        for(i=len-1,j=1; i>=0; i--,j++)
            sum += ((arr[i]-'0')*(pow(2,j)-1));
        printf("%lld\n",sum);
    }
    return 0;
}
