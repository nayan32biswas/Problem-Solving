#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
void solve()
{
    int N, H, x;
    map<int, int> store;
    scanf("%d%d", &N, &H);
    arr.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        store[arr[i]]++;
    }
    bool ans = true;
    if (N % H != 0)
        ans = false;
    sort(arr.begin(), arr.end());
    for (int i = 0, start; i < N && ans; i++)
        if (store[arr[i]])
        {
            start = arr[i];
            for (int j = start; j < start + H; j++)
            {
                x = store[j]--;
                if (x == 0)
                {
                    ans = false;
                    break;
                }
            }
        }
    puts(ans ? "True" : "False");
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test = 0;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        // printf("Case %d: ", t);
        solve();
    }
    return 0;
}