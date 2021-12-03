#include <bits/stdc++.h>
using namespace std;
int main()
{
    int b, k, x, coun = 0;
    cin >> b >> k;
    b = b & 1;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        if (b && x & 1)
        {
            coun++;
            x = 0;
        }
    }
    coun += (x & 1);
    if (coun & 1)
        puts("odd");
    else
        puts("even");

    return 0;
}