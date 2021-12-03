#include <bits/stdc++.h>
using namespace std;
vector<int> dif, coun(27);
vector<pair<int, int>> ans;
bool solved;
bool find(string S, string T, int pos)
{

    if (solved || S == T)
    {
        solved = true;
        return true;
    }
    int len = dif.size();
    if (pos >= len)
        return false;
    bool first = false, second = false;
    for (int j = 0, lo, hi; j < len; j++)
    {
        lo = dif[j], hi = dif[pos];
        if (S[hi] != T[lo] && solved == false)
        {
            first = find(S, T, pos + 1);
            // printf("First: %d %d\n", hi, lo);
            if (first)
            {
                return false;
            }
            swap(S[lo], T[hi]);
            second = find(S, T, pos + 1);
            // cout << "Second: " << hi << " " << lo << " " << S << " " << T << endl;

            if (second && solved)
            {
                // printf("come to insert\n");
                ans.push_back(make_pair(lo, hi));
                return true;
            }
        }
    }
    return false;
}
int solve()
{
    int n;
    scanf("%d", &n);
    string S, T;
    cin >> S >> T;
    // dif.clear();
    ans.clear();
    solved = false;
    fill(coun.begin(), coun.end(), 0);
    for (int i = 0; i < n; i++)
    {
        coun[S[i] - 'a']++;
        coun[T[i] - 'a']++;
    }
    for (auto it : coun)
    {
        if ((it & 1))
            return 0 * puts("NO");
    }

    // find(S, T, 0);

    for (int i = 0; i < n; i++)
    {
        if (S[i] != T[i])
        {
            for (int j = i + 1; j < n; j++)
            {
                if (S[i] == S[j])
                {
                    swap(S[j], T[i]);
                    ans.push_back(make_pair(j, i));
                    break;
                }
                if (S[i] == T[j])
                {
                    swap(S[j], T[j]);
                    swap(S[j], T[i]);
                    ans.push_back(make_pair(j, j));
                    ans.push_back(make_pair(j, i));
                    break;
                }
            }
        }
    }

    // reverse(ans.begin(), ans.end());
    puts("YES");
    cout << ans.size() << endl;
    for (auto it : ans)
    {
        printf("%d %d\n", it.first + 1, it.second + 1);
    }
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