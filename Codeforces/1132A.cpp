#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cnt1, cnt2, cnt3, cnt4;
    cin >> cnt1 >> cnt2 >> cnt3 >> cnt4;
    if (cnt1 != cnt4 || (cnt3 > 0 && cnt1 == 0))
    {
        return 0 * puts("0");
    }
    puts("1");
}