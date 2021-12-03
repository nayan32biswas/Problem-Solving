#include <stdio.h>
int main()
{
    int n, k, i, ans=0, temp;
    scanf("%d%d", &n, &k);
    for(i=0; i<n; i++){
        scanf("%d", &temp);
        if(temp>=k){
            ans += (temp/k);
            temp = temp%k;
        }
        if(temp>0)ans++;
    }
    ans++;
    printf("%d\n", ans/2);
}
