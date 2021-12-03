#include <bits/stdc++.h>
using namespace std;
int solve()
{
    int a, b;
    cin >> a >> b;
    if (a > 9 || b > 9)
        return -1;
    return a * b;
}
int main()
{
    cout << solve() << endl;
}