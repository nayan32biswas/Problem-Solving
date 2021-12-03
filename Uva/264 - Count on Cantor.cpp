#include <bits/stdc++.h>
using namespace std;
pair<int, int>ans[10000007];
int main() {
    int n, x, y;
    x = 1, y = 1;
    bool ck, tck=true;
    ans[1] = make_pair(1, 1);
    for(int i=2; i<=10000000; i++) {
        if(x==1 && tck) {
            ck = true;
            y++;
            tck = false;
        } else if(y==1 && tck) {
            ck = false;
            x++;
            tck = false;
        } else if(ck) x++, y--, tck=true;
        else x--, y++, tck=true;
        ans[i] = make_pair(x, y);
    }
    while(scanf("%d", &n)==1) {
        printf("TERM %d IS %d/%d\n", n, ans[n].first, ans[n].second);
    }
    return 0;
}
