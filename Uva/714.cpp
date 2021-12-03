#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
vector<lli> arr;
vector<bool> isBook;
int n, m;

bool find(lli mid)
{
    lli sum = 0;
    int coun = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        sum += arr[i];
        if (sum > mid)
        {
            sum = arr[i];
            coun++;
        }
    }
    return coun <= m;
}

lli binary_search_lower(lli sum, lli Max)
{
    lli start = Max, End = sum, mid;
    while (End - start > 1)
    {
        mid = (start + End) / 2;
        if (find(mid))
            End = mid;
        else
            start = mid;
    }
    if (find(start))
        return start;
    return End;
}

void split(lli mid)
{
    lli sum = 0, coun = m - 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (arr[i] + sum > mid || coun == i + 1)
        {
            --coun;
            isBook[i] = true;
            sum = 0;
        }
        sum += arr[i];
    }
}
void solve()
{
    scanf("%d%d", &n, &m);
    arr.resize(n);
    isBook.resize(n + 1);
    lli sum = 0, Max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        isBook[i] = false;
        Max = max(Max, arr[i]);
        sum += arr[i];
    }
    lli mid = binary_search_lower(sum, Max);
    split(mid);
    for (int i = 0; i < n; ++i)
    {
        if (i)
            printf(" ");
        printf("%lld", arr[i]);
        if (isBook[i])
            printf(" /");
    }
    printf("\n");
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
