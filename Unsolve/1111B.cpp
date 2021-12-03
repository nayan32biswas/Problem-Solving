#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
int n;
void show(vector<ppi> &arr)
{
    for (auto it : arr)
    {
        printf("%d,%d\t", it.first, it.second);
    }
    puts("");
}
double normalize(vector<ppi> &arr, long long &sum, int &pos, int inc)
{
    if (inc == pos)
    {
        pos++;
        sum -= (arr[inc].first + arr[inc].second);
        arr[inc].second = 0;
    }
    else
    {
        if (arr[pos].second == 0)
        {
            pos++;
        }
        if (pos == n)
        {
            return 0;
        }
        arr[pos].second--;
        if (arr[pos].second == 0)
        {
            pos++;
        }
        sum--;
        sum -= arr[inc].first;
    }
    // show(arr);
    // cout << sum << " " << inc << "\n\n";
    return (double(sum) / (n - inc - 1));
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int k, m;
    long long sum = 0;
    scanf("%d%d%d", &n, &k, &m);
    vector<ppi> arr(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].first);
        sum += arr[i].first;
    }
    sort(arr.begin(), arr.end());
    int pos = 0;
    for (int i = n - 1; i >= 0; i--)
    {

        if (m >= k)
        {
            sum += k;
            arr[i].second = k;
            m -= k;
        }
        else
        {
            sum += m;
            arr[i].second = m;
            m = 0;
            pos = i;
            break;
        }
    }
    // show(arr);
    // cout << sum << "\n\n";
    double ans = double(sum) / n, temp;
    for (int i = 0; i < n - 1; i++)
    {
        temp = normalize(arr, sum, pos, i);
        if (temp == 0)
            break;
        ans = max(ans, temp);
    }
    printf("%.7lf\n", ans);
    return 0;
}