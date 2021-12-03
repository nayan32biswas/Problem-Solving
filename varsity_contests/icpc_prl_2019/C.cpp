#include <bits/stdc++.h>
using namespace std;
#define Size 1000
vector<int> v[Size];
struct team
{
    int id;
    int solve;
    int penalty;
    int forzen;
    int total_solve;
    int total_p;
};
team ar[Size];
int demo[Size];
int main()
{
    // freopen("input.txt", "r", stdin);
    int test, total, x, n;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        for (int i = 0; i < Size; i++)
        {
            v[i].clear();
        }
        memset(ar, 0, sizeof(ar));
        total = 0, x = 0, n = 0;
        printf("Case %d: ", t);
        cin >> total;
        for (int i = 1; i <= total; i++)
        {
            cin >> ar[i].id;
            cin >> ar[ar[i].id].solve >> ar[ar[i].id].penalty >> ar[ar[i].id].forzen;
            for (int j = 0; j < ar[ar[i].id].forzen; j++)
            {
                cin >> x;
                v[ar[i].id].push_back(x);
            }
        }
        bool flag = true;

        int total_solve, total_penalty;
        for (int j = 0; j < total; j++)
            scanf("%d", &demo[j]);
        x = demo[0];
        total_penalty = ar[x].penalty;
        total_solve = ar[x].solve;
        for (auto u : v[ar[x].id])
        {
            total_penalty += u;
        }
        total_solve += ar[x].forzen;
        //cout << total_solve << " " << total_penalty << endl;

        for (int i = 1; i < total; i++)
        {
            x = demo[i];
            int p_penalty = ar[x].penalty;
            int p_solve = ar[x].solve;
            if (total_solve < p_solve)
            {
                flag = false;
                break;
            }
            if (total_penalty > p_penalty && total_solve == p_solve)
            {
                flag = false;
                break;
            }
            for (int k = 0, u; k < v[x].size(); k++)
            {
                u = v[x][k];
                if (p_solve + 1 < total_solve)
                {
                    p_solve++;
                    p_penalty += u;
                }
                else if (p_solve + 1 == total_solve)
                {
                    if (p_penalty + u >= total_penalty)
                    {
                        p_solve++;
                        p_penalty += u;
                    }
                    break;
                }
                else
                    break;
            }
            total_penalty = p_penalty;
            total_solve = p_solve;
            //cout << total_solve << " " << total_penalty << endl;
        }
        //cout << flag << endl;
        if (!flag)
        {
            puts("Say no to rumour >:");
        }
        else
        {
            puts("We respect our judges :)");
        }
    }
    return 0;
}