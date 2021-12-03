#include <bits/stdc++.h>
typedef long long int lli;
#define ull unsinged long long
using namespace std;
vector<int> arr(100005);

int find(lli num)
{
    int coun = 0;
    while (num > 1)
    {
        if (num & 1)
            coun++;
        coun++;
        num /= 2;
    }
    return coun;
}
void solve()
{
    int n, q, l, r;
    lli num;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &num);
        arr[i] = find(num)+arr[i-1];
    }
    for(int i=0; i<q; i++){
        scanf("%d%d", &l, &r);
        printf("%d\n", arr[r]-arr[l-1]);
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