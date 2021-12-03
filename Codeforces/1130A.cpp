#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    map<int, int> mark;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x < 0)
            mark[-1]++;
        else if (x > 0)
            mark[1]++;
        else
            mark[0]++;
    }
    int ans = 0, Max = n / 2;
    if (n & 1)
        Max++;
    if (mark[1] >= Max)
        puts("1");
    else if (mark[-1] >= Max)
        puts("-1");
    else
        puts("0");
}