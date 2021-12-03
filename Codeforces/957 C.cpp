#include <bits/stdc++.h>
using namespace std;
#define Size 1000009
#define fix(n) fixed<<setprecision(n)
int arr[Size], n, U;
double cal(int i, int k) {
    return (double(arr[k]-arr[i+1])/double(arr[k]-arr[i]));
}
int Binary_search(int start);
int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &U);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    double ans = 0;
    bool check = false;
    for(int i=0, X; i<(n-2); i++) {
        X = Binary_search(i);
        if(X>0 && X<n) {
            ans = max(ans, cal(i, X));
            check = true;
        }
    }
    if(check) {
        cout<<fix(9)<<ans<<endl;
    } else {
        puts("-1");
    }
    return 0;
}
int Binary_search(int start) {
    int num = arr[start];
    start+=2;
    int End = n-1, mid, temp, Max=-1;
    while(start<=End) {
        mid = (start+End)>>1;
        temp = arr[mid]-num;
        if(temp>U) {
            End = mid-1;
        } else if(temp<=U) {
            Max = max(Max, mid);
            start = mid+1;
        } else if(temp==U) {
            return mid;
        }
    }
    return Max;
}
