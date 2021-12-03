#include <bits/stdc++.h>
using namespace std;
#define Size 5005
int arr[Size], segSum[Size];
#define queSum(lo, hi) segSum[hi]-segSum[lo]
double Find(int k, int n){
    long long sum = queSum(0, k), Max = sum;
    for(int lo=0, hi=k; hi<n; lo++, hi++){
        sum -= arr[lo];
        sum += arr[hi];
        Max = max(Max, sum);
    }
    return (double)Max/k;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    segSum[1] = arr[0];
    for(int i=0; i<n; i++)
        segSum[i+1] = segSum[i]+arr[i];

    double ans = -LONG_MAX*1.0;
    for(; k<=n; k++){
        ans = max(ans, Find(k, n));
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}
