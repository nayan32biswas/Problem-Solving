#include <bits/stdc++.h>
using namespace std;
typedef set<int> seti;
int M, ans;
bool END;
void rec(vector<seti> arr)
{
    if (END)
        return;

    vector<seti> next;
    seti temp;
    int len = arr.size();
    for (int i = 1, pos = 0; i < len; i += 2, pos++)
    {
        next.push_back(temp);
        for (auto it : arr[i - 1])
        {
            for (auto it1 : arr[i])
            {
                if (it + it1 <= M)
                {
                    next[pos].insert(it + it1);
                }
            }
        }
    }
    if (len == 1)
    {
        if (!arr[0].empty())
            ans = *arr[0].rbegin();
        END = true;
        return;
    }
    if (len & 1)
    {
        next.push_back(arr[len - 1]);
    }

    rec(next);
}
void solve()
{
    vector<seti> arr;
    seti temp;
    int test, c, len;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
    {
        arr.clear();
        scanf("%d%d", &M, &c);
        for (int i = 0; i < c; i++)
        {
            arr.push_back(temp);
            scanf("%d", &len);
            int x;
            for (int j = 0; j < len; j++)
            {
                scanf("%d", &x);
                if (x <= 200)
                    arr[i].insert(x);
            }
        }
        END = false;
        ans = 0;
        rec(arr);
        printf(ans == 0 ? "no solution\n" : "%d\n", ans);
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    solve();
}