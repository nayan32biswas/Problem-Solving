#include <bits/stdc++.h>
using namespace std;
int solve()
{
    int n;
    scanf("%d", &n);
    string S, T;
    cin >> S >> T;
    vector<int> dif;
    for (int i = 0; i < n; i++)
    {
        if (S[i] != T[i])
        {
            dif.push_back(i);
        }
    }
    if (dif.size() != 2)
        return 0 * puts("NO");
    string tempS = S, tempT = T;
    swap(S[dif[0]], T[dif[1]]);
    if (S == T)
        return 0 * puts("YES");
    S = tempS, T = tempT;
    swap(S[dif[1]], T[dif[0]]);
    if (S == T)
        return 0 * puts("YES");
    puts("NO");
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