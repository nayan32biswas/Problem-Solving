#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> tree, lazy;
void updateRangeUtil(lli pos, lli start, lli End, lli lo, lli hi, lli value);
lli getSumUtil(lli start, lli End, lli lo, lli hi, lli pos);
void updateRange(lli n, lli lo, lli hi, lli value)
{
    updateRangeUtil(0, 0, n - 1, lo, hi, value);
}
lli getSum(lli n, lli lo, lli hi)
{
    if (lo < 0 || hi > n - 1 || lo > hi)
        return -1LL;
    return getSumUtil(0, n - 1, lo, hi, 0);
}
void solve()
{
    lli n, q, t, x, y, v;
    scanf("%lld%lld", &n, &q);
    lli Size = 2 * (lli)pow(2, (lli)(ceil(log2(n)))) - 1;
    tree.resize(Size * 4), lazy.resize(Size * 4);
    fill(tree.begin(), tree.end(), 0);
    fill(lazy.begin(), lazy.end(), 0);
    while (q--)
    {
        scanf("%lld%lld%lld", &t, &x, &y);
        if (t)
        {
            // printf("%lld %lld %lld\n", t, x, y);
            printf("%lld\n", getSum(n, x, y));
        }
        else
        {
            scanf("%lld", &v);
            // printf("%lld %lld %lld %lld\n", t, x, y, v);
            updateRange(n, x, y, v);
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    lli test, n;
    scanf("%lld", &test);
    for (lli t = 1; t <= test; t++)
    {
        printf("Case %lld:\n", t);
        solve();
    }
}
lli getSumUtil(lli start, lli End, lli lo, lli hi, lli pos)
{
    if (lazy[pos] != 0)
    {
        tree[pos] += (End - start + 1) * lazy[pos];
        if (start != End)
        {
            lazy[pos * 2 + 1] += lazy[pos];
            lazy[pos * 2 + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (start > End || start > hi || End < lo)
        return 0;
    if (start >= lo && End <= hi)
        return tree[pos];
    lli mid = (start + End) / 2;
    return getSumUtil(start, mid, lo, hi, (2 * pos + 1)) + getSumUtil(mid + 1, End, lo, hi, (2 * pos + 2));
}

void updateRangeUtil(lli pos, lli start, lli End, lli lo, lli hi, lli value)
{
    if (lazy[pos] != 0)
    {
        tree[pos] += (End - start + 1) * lazy[pos];
        if (start != End)
        {
            lazy[pos * 2 + 1] += lazy[pos];
            lazy[pos * 2 + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (start > End || start > hi || End < lo)
        return;
    if (start >= lo && End <= hi)
    {
        tree[pos] += (End - start + 1) * value;
        if (start != End)
        {
            lazy[pos * 2 + 1] += value;
            lazy[pos * 2 + 2] += value;
        }
        return;
    }
    int mid = (start + End) / 2;
    updateRangeUtil((pos * 2 + 1), start, mid, lo, hi, value);
    updateRangeUtil(pos * 2 + 2, mid + 1, End, lo, hi, value);
    tree[pos] = tree[pos * 2 + 1] + tree[pos * 2 + 2];
}