#include <bits/stdc++.h>
using namespace std;
int findPoint(vector<int> &temp, int totalSum)
{
    int sum = 0;
    int mid = ceil(totalSum / 2.0);
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i])
        {
            sum += temp[i];
            if (sum >= mid)
            {
                return i;
            }
        }
    }
    return 0;
}
void solve()
{
    int row, clm, q;
    int u, v, w;
    int totalSum = 0;
    scanf("%d%d%d", &row, &clm, &q);
    vector<int> xAxisSum(row + 1), yAxisSum(clm + 1);
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        xAxisSum[u] += w;
        yAxisSum[v] += w;
        totalSum += w;
    }
    int x = findPoint(xAxisSum, totalSum);
    int y = findPoint(yAxisSum, totalSum);
    printf("%d %d\n", x, y);
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("Case %d: ", t);
        solve();
    }
    return 0;
}
