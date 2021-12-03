#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    double ans = 1;
    scanf("%d", &n);
    vector<double> arr(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &arr[i]);
    }
    sort(arr.begin(), arr.end(), greater<double>());
    for(int i=1; i<n; i++){
        arr[i] = 2*sqrt(arr[i-1]*arr[i]);
    }
    printf("%.2lf\n", arr[n-1]);
    return 0;
}