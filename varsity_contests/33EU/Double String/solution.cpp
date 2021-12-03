#include <bits/stdc++.h>
using namespace std;
bool solve()
{
    int n;
    string str;
    cin >> n >> str;
    if (n != str.size()){
        cout<<str.size()<<endl;
    }
    if (n & 1)
        return 0;
    for (int i = 0, j = n / 2; j < n; i++, j++)
    {
        if (str[i] != str[j])
            return 0;
    }
    return 1;
}
int main()
{
    freopen("input_1.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
        puts(solve() ? "Yes" : "No");
}