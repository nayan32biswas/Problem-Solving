#include <bits/stdc++.h>
using namespace std;
bool comp(string &A, string &B)
{
    return A + B > B + A;
}
vector<string> arr;
void solve()
{
    int n;
    scanf("%d", &n);
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), comp);
    for (auto it : arr)
        cout << it;
    puts("");
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test = 0;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("Case %d: ", t);
        solve();
    }
    return 0;
}