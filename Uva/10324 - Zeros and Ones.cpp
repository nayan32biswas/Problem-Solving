#include <bits/stdc++.h>
using namespace std;
#define Size 1000000
int ans[Size];
char str[Size];
int main()
{
    int Q, i, j, sum, t=0;
    while(scanf("%s", str)==1){
        scanf("%d", &Q);
        printf("Case %d:\n", ++t);
        sum = 0;
        for(i=1; str[i]; i++){
            if(str[i]!=str[i-1]) sum++;
            ans[i] = sum;
        }
        while(Q--){
            scanf("%d%d", &i, &j);
            if(ans[i]==ans[j]) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
