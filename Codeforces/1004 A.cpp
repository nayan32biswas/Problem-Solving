#include <bits/stdc++.h>
using namespace std;
long long t, past, i, n, d, arr[101], ans;
int main()
{
    for(scanf("%lld%lld", &n, &d); i<n; scanf("%lld", &arr[i++]));
    for(i=0; i<n; i++){
        if(i && arr[i-1]+d<arr[i]-d){
            ans++;
        }
        if(i<n-1 && arr[i]+d<=arr[i+1]-d){
            ans++;
        }
    }
    printf("%lld", ans+2);
}
