#include <bits/stdc++.h>
using namespace std;
#define Sum(num) ((num * (num + 1)) >> 1)
#define range_sum(lo, hi) (Sum(hi) - Sum((lo - 1)))
int Min, Max, lo, hi;
int find(int num)
{
    // cout << range_sum(max(num - Min, 1), (num - 1)) + num + Sum((num - 1)) << endl;
    return range_sum(max(num - Min, 1), (num - 1)) + num + Sum((num - 1));
}
int search(int num)
{
    int i = 1;
    // cout << i << ": ";
    while (find(i) <= num)
    {
        i++;
        // cout << i << ": ";
    }
    return --i;
}
int solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    m -= n;
    if (m == 0)
        return 1;
    if (m < n)
        return 2;
    Min = min(k - 1, n - k);
    Max = max(k - 1, n - k);
    int ans = search(n);
    int total = ans + min(Min, ans - 1);
    // cout << total << endl;
    int remain = m - find(ans);
    int num = total + 2;
    // cout << Min << " " << Max << " " << remain << " " << num << endl;
    while (remain > num && num < n && (Min > 0 || Max > 0))
    {
        remain -= num;
        // cout << Min << " " << Max << " " << remain << " " << num << endl;
        if (Min)
        {
            Min--;
            num++;
        }
        if (Max)
        {
            Max--;
            num++;
        }
        ans++;
    }
    ans += (remain / n);

    return ans + 1;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // 200 6585 2          112
    cout << solve() << endl;
}
