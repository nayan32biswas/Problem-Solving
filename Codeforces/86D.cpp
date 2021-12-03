#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define Size 1000005
struct node
{
    lli left, right;
    int blk, pos;
    lli sum;
};
int block;
lli arr[200005], power[Size];
int coun[Size];
vector<node> query;
bool compare(node &x, node &y)
{
    if (x.blk != y.blk)
        return x.blk < y.blk;
    return x.right < y.right;
}
bool arrange(node &x, node &y)
{
    return x.pos < y.pos;
}
void solve()
{
    int n, q;
    lli sum = 0;
    int currL = 0, currR = 0, left, right;
    scanf("%d%d", &n, &q);
    block = (int)sqrt(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%I64d", &arr[i]);
    }
    node temp;
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &left, &right);
        left--, right--;
        query.push_back({left, right, (left / block), i, 0});
    }
    sort(query.begin(), query.end(), compare);

    for (int i = 0; i < q; i++)
    {
        left = query[i].left, right = query[i].right;
        // printf("%d %d\n", left, right);
        for (; currL < left; currL++)
        {
            sum -= arr[currL] * power[coun[arr[currL]]];
            // printf("%I64d %d\n", arr[currL], coun[arr[currL]]);
            coun[arr[currL]]--;
            sum += arr[currL] * power[coun[arr[currL]]];
        }
        for (; currL > left; currL--)
        {
            sum -= arr[currL - 1] * power[coun[arr[currL - 1]]];
            coun[arr[currL - 1]]++;
            sum += arr[currL - 1] * power[coun[arr[currL - 1]]];
            // printf("%I64d %d\n", arr[currL - 1], coun[arr[currL - 1]]);
        }
        for (; currR <= right; currR++)
        {
            sum -= arr[currR] * power[coun[arr[currR]]];
            coun[arr[currR]]++;
            sum += arr[currR] * power[coun[arr[currR]]];
            // printf("%I64d %d\n", arr[currR], coun[arr[currR]]);
        }
        for (; currR > right + 1; currR--)
        {
            sum -= arr[currR - 1] * power[coun[arr[currR - 1]]];
            // printf("%I64d %d\n", arr[currR - 1], coun[arr[currR - 1]]);

            coun[arr[currR - 1]]--;
            sum += arr[currR - 1] * power[coun[arr[currR - 1]]];
        }
        query[i].sum = sum;
        // puts("");
    }
    // puts("");
    sort(query.begin(), query.end(), arrange);
    for (auto it : query)
    {
        printf("%I64d\n", it.sum);
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    for (lli i = 1; i < Size; i++)
        power[i] = i * i;
    solve();
    return 0;
}
