#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long int lli;
using namespace std;
#define Size 200009
int arr[Size];
void solve()
{
    int n, k, d;
    scanf("%d%d%d", &n, &k, &d);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    map<int, int> store;
    int coun = 0;
    for (int i = 0; i < d; i++)
    {
        if (!store[arr[i]])
        {
            coun++;
        }
        store[arr[i]]++;
    }
    int ans = coun;
    for(int lo=0, hi=d; hi<n; hi++, lo++){
        if(arr[lo]!=arr[hi]){
            store[arr[hi]]++;
            store[arr[lo]]--;
            if(store[arr[hi]]==1)coun++;
            if(store[arr[lo]]==0) coun--;
            ans = min(ans, coun);
        }
    }
    printf("%d\n", ans);
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
    {
        solve();
    }
    return 0;
}
