#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull zero(ull num)
{
    if (num < 0)
        return -1;
    ull count = 0;
    for (ull i = 5; (num / i) > 0; i = i * 5)
        count = count + num / i;
    return count;
}
ull find_ans(ull num)
{
    ull start = 1, End = LONG_LONG_MAX, mid, temp;
    while (start <= End)
    {
        mid = (start + End) >> 1;
        temp = zero(mid);
        if (temp < num)
            start = mid + 1;
        else
            End = mid - 1;
    }
    ull i = 0;
    mid = max(i, mid - 2);
    while (zero(mid) < num)
    {
        mid++;
    }
    return mid;
}
int main()
{
    ull test, num;
    scanf("%llu", &test);
    for (int t = 1; t <= test; t++)
    {
        scanf("%llu", &num);
        printf("%llu\n", find_ans(num));
    }
}