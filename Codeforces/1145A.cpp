#include <bits/stdc++.h>
using namespace std;
int arr[17], n;
int find(int lo, int hi)
{
    for (int i = lo; i < hi; i++)
        if (arr[i] > arr[i + 1])
            return max(find(lo, ((lo + hi) / 2)), find(((lo + hi) / 2) + 1, hi));
    return hi - lo + 1;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; cin >> arr[i], i++);
    cout << find(0, n - 1) << endl;
    return 0;
}