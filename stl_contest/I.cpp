#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    long long sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= sum)
        {
            ans++;
            sum += arr[i];
        }
    }
    printf("%lld\n", ans);
}