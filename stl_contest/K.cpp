#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int x, first = 999, second = 999, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x < second && x > first)
            second = x;
        if (x < first)
        {
            second = first;
            first = x;
        }
    }
    if (second == 999)
        puts("NO");
    else
    {
        printf("%d\n", second);
    }
}