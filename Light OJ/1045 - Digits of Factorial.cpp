#include <bits/stdc++.h>
using namespace std;
#define Size 1000009
double store[Size+5];
void finde(){
    double digit=0;
    for(int i=1; i<=Size; i++){
        digit+=log(i);
        store[i]=digit;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    finde();
    int test, n, base, ans;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d%d", &n, &base);
        printf("Case %d: ", t);
        if(n<=1) puts("1");
        else printf("%d\n", (int)ceil(store[n]/log(base)));
    }
    return 0;
}
