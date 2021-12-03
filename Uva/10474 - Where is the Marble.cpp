#include <bits/stdc++.h>
#define LMT 10000
using namespace std;
int arr[LMT], ans[LMT];
int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int i, N, M, test, t=1, Max, temp;
    while(scanf("%d%d", &N, &test)==2 && (N && test)) {
        memset(arr, 0, sizeof(arr));
        memset(ans, 0, sizeof(ans));
        for(i=0, Max=0; i<N; i++) {
            scanf("%d", &temp);
            arr[temp]++;
            Max = max(Max, temp);
        }Max++;

        for(i=0, temp=0; i<Max; i++)if(arr[i]>0){
             ans[i] = temp+1;
             temp = temp+arr[i];
        }

        printf("CASE# %d:\n", t++);
        while(test--) {
            scanf("%d", &M);
            if(ans[M]) printf("%d found at %d\n", M, ans[M]);
            else printf("%d not found\n", M);
        }
    }
    return 0;
}
