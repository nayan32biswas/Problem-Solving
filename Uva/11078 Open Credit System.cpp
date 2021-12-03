#include <stdio.h>
#define INT_MAX 200000000
int MAX(int x, int y){
    if(x<y) return y;
    return x;
}
int main()
{
    int test, n, Max, ans, x;
    scanf("%d", &test);
    while(test--){
        ans = -INT_MAX;
        scanf("%d%d", &n, &Max);
        while(--n){
            scanf("%d", &x);
            ans = MAX(ans, Max-x);
            Max = MAX(x, Max);
        }
        printf("%d\n", ans);
    }
    return 0;
}
