#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long ull;
using namespace std;
#define Size 20
lli arr[Size];

void solve()
{
    int n;
    lli sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // sum+=arr[i];
    }
    int time = clock();
    unsigned int MAX = pow(2, n);
    lli temp;
    for (int i = 0; i < MAX; i++)
    {
        temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                temp |= arr[j];
                // cout<<arr[j]<<", ";
            }
        }
        // puts("");
        sum += temp;
    }
    // cout << clock() - time << endl;

    cout << sum << endl;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    solve();
    return 0;
}