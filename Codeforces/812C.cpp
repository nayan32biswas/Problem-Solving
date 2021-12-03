#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
vector<lli> arr, temp_arr;
lli n, S, K, BYE;
bool Sum(lli k)
{
    // cout<<k<<endl;
    int i;
    for (i = 0; i < n; i++)
    {
        temp_arr[i] = (arr[i] + (i + 1) * k);
    }
    BYE = 0;
    sort(temp_arr.begin(), temp_arr.end());
    for (i = 0; i < k; i++)
    {
        BYE += temp_arr[i];
    }
    // cout << k << endl;
    // for (i = 0; i < 5; i++)
    // {
    //     cout << temp_arr[i] << " ";
    // }
    // puts("");
    if (BYE <= S)
        return true;
    return false;
}
void search()
{
    lli start = 1, end = n, mid;
    K = 0;
    while (start <= end)
    {
        mid = start + ((end - start) >> 1);
        if (Sum(mid))
        {
            K = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}

void solve()
{
    search();
    Sum(K);
    printf("%lld %lld\n", K, BYE);
}
int main()
{
    // freopen("input.txt", "r", stdin);
    scanf("%lld%lld", &n, &S);
    arr.resize(n);
    temp_arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    solve();
    return 0;
}