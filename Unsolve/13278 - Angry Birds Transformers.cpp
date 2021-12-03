#include <bits/stdc++.h>
using namespace std;
#define Size 10009
typedef pair<int, int> ppi;
int ans[Size], Max;
void SET(int x, int y){
    int lo, hi;
    lo = max(2, x-y);
    hi = min(Size, x+y);
    for(; lo<=hi; lo++) Max = max(Max, ++ans[lo]);
}
int main()
{
    int test, N, x, y;
    while(scanf("%d", &N) && N){
        memset(ans, 0, sizeof(ans));
        Max = 0;
        for(int i=0; i<N; i++){
            scanf("%d%d", &x, &y);
            SET(x, y);
        }
        cout<<Max<<endl;
    }
    return 0;
}

