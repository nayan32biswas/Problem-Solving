#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
bool check;
void each(vec &arr, int i, int value)
{
    if (i > 4 or check == true)
    {
        if (value == 23)
        {
            check = true;
        }
        return;
    }
    if (value > 250 and value < -250)
        return;
    each(arr, i + 1, value + arr[i]);
    each(arr, i + 1, value - arr[i]);
    each(arr, i + 1, value * arr[i]);
}
void permu(vec &arr)
{
    do
    {
        each(arr, 1, arr[0]);
    } while (next_permutation(arr.begin(), arr.end()));
}
int main()
{
    // freopen("input.txt", "r", stdin);
    vector<int> arr(5);
    while (scanf("%d", &arr[0]) and arr[0])
    {
        for (int i = 1; i < 5; i++)
            scanf("%d", &arr[i]);
        check = false;
        sort(arr.begin(), arr.end());
        permu(arr);
        puts(check ? "Possible" : "Impossible");
    }
}