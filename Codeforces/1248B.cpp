#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    long long xaxis = 0, yaxis = 0, mid = (n/2);
    for(int i=mid; i<n; i++)xaxis += arr[i];
    for(int i=0; i<mid; i++)yaxis += arr[i];
    printf("%lld\n", xaxis*xaxis+yaxis*yaxis);
    return 0;
}