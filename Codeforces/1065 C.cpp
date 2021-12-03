#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define Size 200005
int arr[Size];
lli sum[Size];
int k, n, Max, Min = INT_MAX;
int solve(){
    lli coun = 0;
    int ans = 0;
    for(int i=Max; i>Min; i--){
        coun += sum[i];
        sum[i] = sum[i+1]+coun;
    }
    coun = 0;
    for(int i=Max; i>Min; i--){
        sum[i-1] -= coun;
        if(sum[i-1]>k){
            coun += sum[i];
            sum[i-1] -= sum[i];
            ans++;
        }
    }
    if(sum[Min+1]>0) ans++;
    return ans;
}
int main()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
        sum[arr[i]]++;
        Max = max(Max, arr[i]);
        Min = min(Min, arr[i]);
    }
    printf("%d\n", solve());
    return 0;
}

