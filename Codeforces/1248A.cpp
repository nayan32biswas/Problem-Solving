#include <bits/stdc++.h>
using namespace std;
long long test, p, q, n, m, x;

int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        p = 0, q = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x % 2)
                p++;
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            if (x % 2)
                q++;
        }
        cout<<(p*q)+((n-p)*(m-q))<<endl;
    }
}