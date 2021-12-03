#include <bits/stdc++.h>
using namespace std;
int power[] = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431};
int ans[] = {0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};
map<int, int> store;
void str()
{
    for (int i = 0; i < 26; i++)
    {
        store[power[i]] = ans[i];
    }
}
int make(int n)
{
    vector<int> pos;
    int i = 0;
    while (n > 0)
    {
        if ((n & 1) == 0)
        {
            pos.push_back(i);
        }
        i++;
        n /= 2;
    }
    n = 0;
    reverse(pos.begin(), pos.end());
    for (auto it : pos)
    {
        n += int(pow(2, it));
    }
    return n;
}
void solve()
{
    int a;
    scanf("%d", &a);
    if (store[a])
    {
        printf("%d\n", store[a]);
        return;
    }
    int b = make(a);
    // cout << b << endl;
    printf("%d\n", __gcd(a & b, a ^ b));
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int q = 0;
    str();
    scanf("%d", &q);
    while (q--)
    {
        solve();
    }
    return 0;
}