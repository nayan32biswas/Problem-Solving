#include <bits/stdc++.h>
using namespace std;
map<string, int> dbms;
void solve(string &str)
{
    if (!dbms[str])
    {
        dbms[str]++;
        puts("OK");
        return;
    }
    cout<<str<<(dbms[str]++)<<endl;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    string str;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        solve(str);
    }
    return 0;
}