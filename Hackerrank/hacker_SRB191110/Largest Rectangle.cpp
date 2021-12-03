#include <bits/stdc++.h>
using namespace std;
stack<int> st;
void solve()
{
    int n;
    scanf("%d", &n);
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    long long ans = 0, Max2, Max, i = 0;
    while (i < n)
    {
        if (st.empty() || arr[st.top()] <= arr[i])
            st.push(i++);
        else
        {
            Max2 = st.top();
            st.pop();
            Max = arr[Max2] * (st.empty() ? i : i - st.top() - 1);
            if (ans < Max)
                ans = Max;
        }
    }
    while (st.empty() == false)
    {
        Max2 = st.top(), st.pop();
        Max = arr[Max2] * (st.empty() ? i : i - st.top() - 1);
        if (ans < Max)
            ans = Max;
    }
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}
