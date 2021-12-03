#include <bits/stdc++.h>
using namespace std;
#define MAX (1e18)
#define Size 100009
long long A[Size], B[Size];
int arr[Size];

int main() {
    //freopen("input.txt", "r", stdin);
    int n, i;
    long long Max, sum=0, ans=INT_MIN;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        ans = max(ans, (long long)arr[i]);
    }
    sum = 0;
    Max = INT_MIN;
    for(i=0; i<n; i++){
        sum += arr[i];
        Max = max(Max, sum);
        if(sum<0){
            sum = 0;
        }
        A[i] = Max;
    }
    Max = INT_MIN;
    sum = 0;
    for(i=n-1; i>=0; i--){
        sum += arr[i];
        Max = max(Max, sum);
        if(sum<0){
            sum = 0;
        }
        B[i] = Max;
    }
    //for(i=0; i<n; i++) cout<<A[i]<<' ';puts("");
    //for(i=0; i<n; i++) cout<<B[i]<<' ';puts("");
    for(i=1, n--; i<n; i++){
        ans = max(ans, A[i-1]+B[i+1]);
    }
    cout<<ans<<endl;
}
