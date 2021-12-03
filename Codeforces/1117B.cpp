#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int n, m, k, x;
    int first_max = 0, second_max = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x >= first_max)
        {
            second_max = first_max;
            first_max = x;
        }
        else
            second_max = max(x, second_max);
    }
    long long ans = 0, coun = m / (k + 1);
    ans = (coun * k) * first_max;
    ans += second_max * coun;
    coun = m % (k + 1);
    if (coun != 0)
        ans += coun * first_max;
    cout << ans << endl;
    return 0;
}