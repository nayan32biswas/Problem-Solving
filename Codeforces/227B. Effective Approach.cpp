#include <stdio.h>
#include <iostream>
using namespace std;
int arr[100009], arr1[100009];
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, n, m, temp;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &temp);
        arr[temp]=i;
    }
    scanf("%d", &m);
    for(i=1; i<=m; i++)
    {
        scanf("%d", &arr1[i]);
    }
    long long Vasya=0, Petya=0;
    for(i=1; i<=m; i++)
    {
        temp = arr[arr1[i]];
        Vasya+=temp;
        Petya+=(n-temp)+1;
    }
    printf("%lld %lld", Vasya, Petya);
    return 0;
}
