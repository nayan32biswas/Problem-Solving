#include <bits/stdc++.h>
using namespace std;
int main()
{
    int W, H, N, x, y, x1, y1;
    while(scanf("%d%d%d", &W, &H, &N) && N){
        int sum = 0, ans = 0;
        ans = W*H;
        for(int i=0; i<N; i++){
            scanf("%d%d", &x, &y);
            scanf("%d%d", &x1, &y1);
            sum += max(abs(x-x1), 1)*max(abs(y-y1), 1);
        }
        cout<<ans<<" "<<sum<<endl;
        printf("%d\n", ans-sum);
    }
    return 0;
}
