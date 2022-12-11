#include <bits/stdc++.h>
using namespace std;

void first()
{
    freopen("input.txt", "r", stdin);
    int count = 0, prevNum = INT_MAX;
    int num;
    while (scanf("%d", &num) != EOF)
    {
        if (num > prevNum)
            count++;
        prevNum = num;
    }
    printf("%d\n", count);
}

void second()
{
    freopen("input.txt", "r", stdin);
    int count = 0, prevNum = INT_MAX;
    int arr[] = {0, 0, 0};
    int num;
    while (scanf("%d", &num) != EOF)
    {
        arr[0] = arr[1], arr[1] = arr[2], arr[2] = num;
        if (arr[0] == 0)
            continue;
        if (prevNum < arr[0] + arr[1] + arr[2])
            count++;
        prevNum = arr[0] + arr[1] + arr[2];
    }
    printf("%d\n", count);
}

int main()
{
    // first();
    second();

    return 0;
}