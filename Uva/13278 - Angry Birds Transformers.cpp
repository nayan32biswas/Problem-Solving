#include <bits/stdc++.h>
using namespace std;
#define Size 10005
int markCount[Size];
void fastCountRun() {
    for(int i=1; i<Size; i++)
        markCount[i] += markCount[i-1];
}
void fastCount(int lo, int hi) {
    lo = max(0, lo-1); /// one base
    hi = min(Size-2, hi);
    markCount[lo]++;
    markCount[hi]--;
}
int fastCountMax(int lo, int hi) {
    int Max = 0;
    lo = max(lo, 1); /// one base
    for(int i=lo-1; i<hi; i++)
        Max = max(Max, markCount[i]);
    return Max;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int N, x, y, left, right;
    while(scanf("%d", &N) && N) {
        memset(markCount, 0, sizeof(markCount));
        for(int i=0; i<N; i++) {
            scanf("%d%d", &x, &y);
            left = x-y;
            right = x+y;
            fastCount(left, right);
        }
        fastCountRun();
        printf("%d\n", fastCountMax(1, Size));
    }
}
