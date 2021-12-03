#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, arr[55], i, J, k;
    cin>>n>>m;
    for(i=0; i<m; i++){
        scanf("%d", &arr[i]);
    }
    int ans, Max;
    sort(arr, arr+m);
    for(i=0, ans=9999; i<=(m-n); i++){
        for(J=i, Max=0; J<(n+i); J++){
            for(k=J; k<(n+i); k++){
                Max = max(Max, abs(arr[J]-arr[k]));
            }
        }
        ans = min(ans, Max);
    }
    cout<<ans<<endl;
    return 0;
}
