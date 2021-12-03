#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    vector<long long> odd(n + 1), even(n + 1);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        odd[i + 1] = odd[i];
        even[i + 1] = even[i];
        if ((i & 1))
            even[i + 1] += arr[i];
        else
            odd[i + 1] += arr[i];
    }
    int t_odd, t_even, coun = 0;
    for (int i = 0; i < n; i++)
    {
        t_odd = odd[i + 1] - odd[0];
        t_odd += even[n] - even[i + 1];

        t_even = even[i + 1] - even[0];
        t_even += odd[n] - odd[i + 1];
        if (i & 1)
            t_even -= arr[i];
        else
            t_odd -= arr[i];
        if (t_odd == t_even)
            coun++;
    }
    printf("%d\n", coun);
    return 0;
}