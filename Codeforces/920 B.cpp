#include <stdio.h>
using namespace std;
int main(){
    //freopen("input.txt", "r", stdin);
    int test, n, l, r;
    scanf("%d", &test);
    for(int t=0; t<test; t++){
        if(t) puts("");
        scanf("%d", &n);
        int ans = 1;
        for(int i=0; i<n; i++){
            scanf("%d%d", &l, &r);
            if(i) printf(" ");
            if(ans<l){
                ans = l+1;
                printf("%d", l);
            }
            else if(ans>=l && ans<=r){
                printf("%d", ans);
                ans++;
            }
            else printf("0");
        }

    }
    return 0;
}
