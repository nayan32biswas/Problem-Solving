#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string action, link, current = "http://www.lightoj.com/";
    stack<string> backword, forword;
    while (cin >> action && action != "QUIT")
    {
        if (action == "VISIT")
        {
            cin >> link;
            while (forword.size())
                forword.pop();
            backword.push(current);
            current = link;
            cout << current << endl;
        }
        else if (action == "BACK")
        {
            if (backword.size())
            {
                forword.push(current);
                current = backword.top();
                backword.pop();
                cout << current << endl;
            }
            else
            {
                puts("Ignored");
            }
        }
        else if (action == "FORWARD")
        {
            if (forword.size())
            {
                backword.push(current);
                current = forword.top();
                forword.pop();
                cout << current << endl;
            }
            else
            {
                puts("Ignored");
            }
        }
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("Case %d:\n", t);
        solve();
    }
    return 0;
}