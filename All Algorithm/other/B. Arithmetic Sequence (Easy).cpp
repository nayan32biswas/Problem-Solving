#include <cstdio>
int main()
{
    int N, M, sum, x;
    scanf("%d%d", &N, &M);
    sum=((N*(N+1))/2);
    for(int i=0; i<M; i++){
        scanf("%d", &x);
        sum-=x;
    }
    printf("%d\n", sum);
    return 0;
}
