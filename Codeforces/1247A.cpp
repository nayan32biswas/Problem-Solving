#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long int lli;
using namespace std;
#define Size 100009
int arr[Size];
void solve()
{
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 9 && b == 1)
    {
        puts("9 10");
    }
    else if (abs(a - b) > 1 or a > b)
    {
        puts("-1");
    }
    else if (a == b)
    {
        printf("%d1 %d2\n", a, b);
    }
    else
    {

        cout << a << " " << b << endl;
    }
    return 0;
}
