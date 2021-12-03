#include <bits/stdc++.h>
using namespace std;
#define SizeOfn 101
#define SizeOfsum 50001
bool dp[SizeOfn][SizeOfsum];
int arr[SizeOfn];
int FindMin(int arr[], int n) {
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    for(int i=0; i<=n; i++)
        dp[i][0] = true;
    for(int i=1; i<=sum; i++)
        dp[0][i] = false;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j){
                dp[i][j] |= dp[i-1][j-arr[i-1]];
            }
        }
    }
    for (int j=sum/2; j>=0; j--) {
        if (dp[n][j] == true) {
            return sum-2*j;
        }
    }
    return INT_MAX;
}
int main() {
    int test, N;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%d", &arr[i]);
        printf("%d\n", FindMin(arr, N));
    }
    return 0;
}
