#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> arr;
int find(int mid)
{
    return arr[mid];
}
int binary_search_upper(int key, int n)
{
    int start = 0, End = n - 1;
    while (End - start > 1)
    {
        int mid = (start + End) / 2;
        if (find(mid) >= key)
            End = mid;

        else
            start = mid;
    }
    if (find(start) >= key)
        return start;
    return End;
}

int main()
{
    int n, x;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int q, mid;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &x);
        mid = binary_search_upper(x, n);
        if (arr[mid] == x)
            printf("Yes %d\n", mid + 1);
        else
        {

            printf("No %d\n", mid + 1);
        }
    }
    return 0;
}
