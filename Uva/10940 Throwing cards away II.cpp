#include <bits/stdc++.h>
using namespace std;
int Find(int n);
int arr[20];
int main() {
    //freopen("input.txt", "r", stdin);
    for(int i=1; i<20; i++)
        arr[i] = 1<<i;
    int n, x;
    while(scanf("%d", &n) && n) {
        if(n<3){
            n==1 ? puts("1") : puts("2");
            continue;
        }
        x=0;
        while(arr[++x]<n);
        x--;
        printf("%d\n", (n-arr[x])*2);
    }
    return 0;
}
int Find(int n) {
    if(n==1) return 1;
    queue<int>Q;
    for(int i=2; i<=n; i+=2)
        Q.push(i);
    if(n&1) {
        Q.push(Q.front());
        Q.pop();
    }
    while(true) {
        if(Q.size()==1) {
            n = Q.front();
            Q.pop();
            break;
        } else {
            Q.pop();
            Q.push(Q.front());
            Q.pop();
        }
    }
    return n;
}
