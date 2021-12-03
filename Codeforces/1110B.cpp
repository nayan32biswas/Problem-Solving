#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> &A, pair<int, int> &B)
{
    return A.second < B.second;
}
void show(vector<pair<int, int>> &temp)
{
    for (auto it : temp)
    {
        cout << it.first << " " << it.second << endl;
    }
    puts("");
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int n, k, m;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> arr(n);
    vector<pair<int, int>> temp(n - 1);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    if (n == k)
    {
        cout << n << endl;
        return 0;
    }
    if (k == 1)
    {
        cout << arr[n - 1] - arr[0] + 1 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        temp[i].first = arr[i + 1] - arr[i];
        temp[i].second = i;
    }
    sort(temp.begin(), temp.end());
    // show(temp);
    for (int i = n - 2, j = k - 1; i >= 0 && j > 0; i--, j--)
    {
        temp[i].first = 0;
    }
    sort(temp.begin(), temp.end(), comp);

    arr.push_back(arr[n-1]);
    temp.push_back(make_pair(0, n));

    // show(temp);
    long long sum = 0, prev = arr[0];

    for (auto it : temp)
    {
        if (it.first == 0)
        {
            // cout<<prev<<" "<<arr[it.second]<<endl;
            prev = arr[it.second]-prev;
            sum = sum + prev+1;

            prev = arr[it.second+1];
        }
    }
    cout<<sum<<endl;
}