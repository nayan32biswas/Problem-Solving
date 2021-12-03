#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull find(ull num)
{
    return (num * (num + 1) * (2 * num + 1)) / 6;
}
ull find_ans(ull num)
{
    ull start = 1, End = 100000009, mid, temp;
    while (start <= End)
    {
        mid = (start + End) >> 1;
        temp = find(mid);
        if (temp < num)
            start = mid + 1;
        else
            End = mid - 1;
    }
    ull i = 0;
    mid = max(i, mid - 2);
    while (find(mid) < num)
    {
        mid++;
    }
    if (find(mid) > num)
        mid--;
    return mid;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    ull test, num;
    scanf("%llu", &test);
    for (int t = 1; t <= test; t++)
    {
        scanf("%llu", &num);
        printf("%llu\n", find_ans(num));
    }
}