#include <bits/stdc++.h>
using namespace std;
#define Size 1000
#define low(pos) max(pos-r+1, 1)
#define hhi(pos) min(pos+r-1, n)
int n, r, arr[Size];
void Find(stack<int>&stk) {
    if(stk.size()>0)
        stk.pop();
    while(!stk.empty())
        arr[stk.top()] = 0, stk.pop();
}
void Delete(int pos) {
    stack<int>stk;
    int bound = (r-1)*2+1+pos;
    for(int i=pos+1; i<=n && i<=bound; i++)
        if(arr[i])
            stk.push(i);
    Find(stk);
}

void rRight() {
    stack<int>stk;
    for(int i=n; i>=1; i--)
        if(arr[i]) {
            if(hhi(i)>=n)
                stk.push(i);
            else
                break;
        }
    Find(stk);
}
void rLeft() {
    stack<int>stk;
    for(int i=1; i<=n; i++)
        if(arr[i]) {
            if(low(i)<=1)
                stk.push(i);
            else
                break;
        }
    Find(stk);
}
int temp[Size];
void mark(int pos) {
    for(int lo = low(pos), hi = hhi(pos); lo<=hi; lo++)
        temp[lo] = pos;
}
void solve() {
    rLeft();
    rRight();
    //for(int i=1; i<=n; i++)cout<<arr[i]<<" "; puts("");
    for(int i=1; i<=n; i++) {
        if(arr[i]==1) {
            Delete(i);
        }
    }
    for(int i=1; i<=n; i++)cout<<arr[i]<<" "; puts("");
    for(int i=1; i<=n; i++) {
        if(arr[i]==1) {
            mark(i);
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(temp[i]==0) {
            puts("-1");
            return;
        }
        if(arr[i]==1)
            ans++;
    }
    cout<<ans<<endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &r);
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    solve();
    return 0;
}
/*
11 3
1 0 0 0 1   0 1 0 0 0 1
*/
