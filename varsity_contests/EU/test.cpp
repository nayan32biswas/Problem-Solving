#include <bits/stdc++.h>
using namespace std;
int mark[1000006];
void Mark(int lo, int hi)
{
    for (; lo <= hi; lo++)
    {
        mark[lo]++;
    }
}
void ans(int n)
{
    int Max = 0, loc;
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] > Max)
        {
            Max = mark[i];
            loc = i;
        }
    }
    cout << loc << " " << Max << endl;
}

int main()
{
    int n, test, x, y;
    cin >> n >> test;
    for (int i = 0; i < test; i++)
    {
        scanf("%d%d", &x, &y);
        Mark(x, y);
    }
    ans(n);
    return 0;
}