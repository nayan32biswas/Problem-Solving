#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int x1, y1, x2, y2, M, test, x, y;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        scanf("%d", &M);
        printf("Case %d:\n", t);
        while(M--){
            scanf("%d%d", &x, &y);
            //cout<<x<<' '<<y<<endl;
            if((x>=x1 && x<=x2) && (y>=y1 && y<=y2)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
