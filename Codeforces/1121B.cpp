#include <bits/stdc++.h>
using namespace std;
#define Size 100005
int arr[Size], mark[Size * 2];
int main()
{
    int n, Max = 0, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            x = ++mark[arr[i] + arr[j]];
            if (x > Max)
                Max = x;
        }
    }
    printf("%d\n", Max);
}