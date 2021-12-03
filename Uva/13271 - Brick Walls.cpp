#include <bits/stdc++.h>
using namespace std;
bool check(long long x, long long y) {
    return ((x%2==1 && y%2==0) || (x%2==0 && y%2==1));
}
long long solve(long long x, long long y, long long x1, long long y1) {
    if(x==x1)
        return abs(y-y1);
    long long extra, left, right, ans=0;
    long long xTox = abs(x-x1), yPoint;
    extra = (xTox-1)*2+1;
    if(!check(x, y)) {
        yPoint = y;
    } else {
        yPoint = y+1;
        ans++;
    }
    left = yPoint-(extra/2);
    right = yPoint+(extra/2);
    /// y1>right already done.
    if(y1<left && check(x, y)) {
        yPoint -= 2;
        left -= 2;
        right -= 2;
    }
    if(left==y1 || right==y1) {
        return ans+extra;
    }

    if(y1<left) {
        ans += (left-y1);
    } else if(y1>right) {
        ans += (y1-right);
    } else if(!check(x1, y1))
        ans++; /// under the range.
    return ans+extra;
}
int main() {
    int x, y, x1, y1;
    while(scanf("%d%d%d%d", &x, &y, &x1, &y1) && x) {
        if(x>x1) {
            swap(x, x1);
            swap(y, y1);
        }
        cout<<solve(x, y, x1, y1)<<endl;
    }
    return 0;
}
