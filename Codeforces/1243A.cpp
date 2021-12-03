#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    scanf("%d", &n);
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, min(i+1, arr[i]));
    }
    printf("%d\n", ans);
}
int main()
{
    int test;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        solve();
    }
    return 0;
}