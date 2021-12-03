#include <bits/stdc++.h>
typedef long long int lli;
#define ull unsinged long long
using namespace std;
void solve()
{
    int n, bed = 0, living = 0, kitchen = 0;
    scanf("%d", &n);
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str[0] == 'b' && str[1] == 'e' && str[2] == 'd')
        {
            bed++;
        }
        else if (str[0] == 'l' && str[1] == 'i' && str[2] == 'v' && str[3] == 'i' && str[4] == 'n' && str[5] == 'g')
        {
            living++;
        }
        else
        {
            kitchen++;
        }
    }
    bed /= 2;
    printf("%d\n", min(bed, min(living, kitchen)));
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        solve();
    }
    return 0;
}