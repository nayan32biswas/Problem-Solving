#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int main()
{
    // freopen("input.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    arr.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    N = arr.size();
    int Q, x, lo, hi, pos;
    scanf("%d", &Q);
    while (Q--)
    {
        scanf("%d", &x);
        pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        lo = pos;
        while (lo >= 0 && arr[lo] >= x)
            lo--;
        hi = pos;
        while (hi < N && arr[hi] <= x)
            hi++;
        if (lo < 0 and hi >= N)
            puts("X X");
        else if (lo < 0 and hi < N)
            printf("X %d\n", arr[hi]);
        else if (hi >= N and lo >= 0)
            printf("%d X\n", arr[lo]);
        else
            printf("%d %d\n", arr[lo], arr[hi]);
        // cout << lo << " " << hi << endl;
    }
    return 0;
}