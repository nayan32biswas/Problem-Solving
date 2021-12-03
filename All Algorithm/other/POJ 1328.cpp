#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <math.h>

#define ppi pair<double, double>
using namespace std;

int solve(int n, int d)
{
    int x, y, Max = 0;
    double point;
    vector<ppi> arr;
    for (double i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        Max = max(y, Max);
        point = sqrt(double(abs(d * d - y * y)));
        arr.push_back(make_pair(x - point, x + point));
        // cout << x - point << " " << x + point << " " << point << endl;
    }
    if (Max > d)
        return -1;
    sort(arr.begin(), arr.end());
    double r = INT_MAX;
    int ans = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].second < r)
            r = arr[i].second;
        if (arr[i].first > r)
        {
            r = arr[i].second;
            ans++;
        }
    }
    return ans;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int n, d, test = 1;
    while (scanf("%d%d", &n, &d) && n && d)
    {
        printf("Case %d: %d\n", test++, solve(n, d));
    }
}
