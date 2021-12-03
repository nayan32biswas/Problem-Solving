#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define Size 30005
struct node
{
    int left, right, blk, pos;
    int sum;
};
int block;
int arr[Size], coun[1000005];
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
    int currL = 0, currR = 0, sum = 0;
    int left, right;
    scanf("%d", &n);
    block = (int)sqrt(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &q);
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
        for (; currL < left; currL++)
        {
            coun[arr[currL]]--;
            if (coun[arr[currL]] == 0)
                sum--;
        }
        for (; currL > left; currL--)
        {
            if (coun[arr[currL - 1]] == 0)
                sum++;
            coun[arr[currL - 1]]++;
        }
        for (; currR <= right; currR++)
        {
            if (coun[arr[currR]] == 0)
                sum++;
            coun[arr[currR]]++;
        }
        for (; currR > right + 1; currR--)
        {
            coun[arr[currR - 1]]--;
            if (coun[arr[currR - 1]] == 0)
                sum--;
        }
        query[i].sum = sum;
    }
    sort(query.begin(), query.end(), arrange);
    for (auto it : query)
    {
        printf("%d\n", it.sum);
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
