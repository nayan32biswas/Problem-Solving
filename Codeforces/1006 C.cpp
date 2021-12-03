#include <bits/stdc++.h>
using namespace std;
#define Size 200005
int arr[Size], n;
long long queSum[Size];
#define queSum(lo, hi) (queSum[hi]-queSum[lo])
bool MID(int pos, long long key) {
    int start = pos, End = n, mid;
    long long temp;
    //cout<<key<<endl;
    while(start<=End) {
        mid =(start+End)/2;
        temp = queSum(mid, n);
        //cout<<mid<<" "<<temp<<endl;
        if(temp==key)
            return true;
        if(temp<key) {
            End = mid-1;
        } else {
            start = mid+1;
        }
    }
    return false;
}
int main() {
    //freopen("input.txt", "r", stdin);
    long long totalSum = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        totalSum += arr[i];
        queSum[i+1] = totalSum;
    }
    long long ans = 0;
    for(int i=n-1; i>0; i--) {
        if(MID(i, queSum(0, i))) {
            cout<<queSum(0, i)<<endl;
            return 0;
        }
    }
    puts("0");
    return 0;
}
