#include <bits/stdc++.h>
using namespace std;
int arr[110];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    if(n==1){
        puts("1");
        return;
    }
    sort(arr, arr+n);
    for(int i=1; i<n; i++){
        if(arr[i]-arr[i-1]==1){
            puts("2");
            return;
        }
    }
    puts("1");
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        solve();
    }

    return 0;
}