#include <bits/stdc++.h>
using namespace std;
bool find_each(int num)
{
    int coun = 0;
    for (int p = 2; p * p <= num && coun < 2; p++)
    {
        if (num % p == 0)
        {
            while (num % p == 0)
                num /= p;
            coun++;
        }
    }
    if (num > 1)
        coun++;
    return coun == 2;
}
int main()
{
    int num, coun = 0;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        if (find_each(i))
            coun++;
    }
    printf("%d\n", coun);
    return 0;
}