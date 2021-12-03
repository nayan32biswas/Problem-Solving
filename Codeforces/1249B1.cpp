#include <bits/stdc++.h>
using namespace std;
#define Size 209
int arr[Size], ans[Size];
int find_ans(int pos)
{
    int child = pos, coun = 1;
    while (arr[pos] != child)
    {
        coun++;
        pos = arr[pos];
    }
    return coun;
}
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            printf(" ");
        printf("%d", find_ans(arr[i]));
    }
    puts("");
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