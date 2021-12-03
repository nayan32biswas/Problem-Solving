#include <bits/stdc++.h>
using namespace std;
#define Size 3655
bool mark[Size];
int main() {
    int test;
    scanf("%d", &test);
    for(int t=0; t<test; t++) {
        int N, Q;
        scanf("%d%d", &N, &Q);
        memset(mark, 0, sizeof(mark));
        for(int i=0; i<Q; i++) {
            int day, temp;
            scanf("%d", &day);
            temp = day;
            while(temp<=N) {
                mark[temp] = 1;
                temp += day;
            }
        }
        int ans = 0;
        for(int i=1; i<=N; i++)
            if(i%7!=0 && i%7!=6)
                if(mark[i])
                    ans++;
        printf("%d\n", ans);
    }
    return 0;
}

