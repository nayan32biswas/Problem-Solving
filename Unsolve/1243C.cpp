#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
lli find(lli num)
{
    if (num <= 2)
        return num;
    if (num % 2 == 0)
        return num / 2;
    for (lli i = 3; i * i <= num; i += 2)
    {
        if (num % i)
            return num / i;
    }
    return num;
}
int main()
{
    lli num;
    cin >> num;
    cout << find(num) << endl;
}