#include <bits/stdc++.h>
using namespace std;
#define NumSize 1000005
vector<int> coprime(NumSize + 5);
void computeTotient()
{
    for (int i = 1; i <= NumSize; i++)
        coprime[i] = i;
    for (int p = 2; p <= NumSize; p++)
    {
        if (coprime[p] == p)
        {
            coprime[p] = p - 1;
            for (int i = 2 * p; i <= NumSize; i += p)
            {
                coprime[i] = (coprime[i] / p) * (p - 1);
            }
        }
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    computeTotient();
    int test, num;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        scanf("%d", &num);
        printf("%d\n", coprime[num]);
    }
    return 0;
}