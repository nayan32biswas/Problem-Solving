#include <bits/stdc++.h>
using namespace std;
#define not_valid 1000000001
typedef pair<int, int> ppi;
bool comp(ppi &A, ppi &B)
{
    return A.second < B.second;
}
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<ppi> arr(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end(), greater<>());
    long long sum = 0;
    vector<int> ans;
    for (int i = 0; i < min(n, m * k); i++)
    {
        sum += arr[i].first;
        arr[i].first = not_valid;
    }
    sort(arr.begin(), arr.end(), comp);
    for (int i = 0, mmm = m; i < n; i++)
    {
        if (arr[i].first == not_valid)
            mmm--;
        if (mmm == 0)
        {
            mmm = m;
            ans.push_back(arr[i].second+1);
        }
    }
    ans.pop_back();
    printf("%lld\n", sum);
    for (auto it : ans)
    {
        printf("%d ", it);
    }
    puts("");
    return 0;
}