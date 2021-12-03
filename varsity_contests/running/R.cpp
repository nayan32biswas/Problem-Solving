#include <bits/stdc++.h>
using namespace std;

int pir[] = {2, 3, 5, 7, 11, 13, 17};
set<int> pir_set(pir, pir + (sizeof(pir) / sizeof(int)));
vector<set<int>> sidePrime;
map<int, vector<vector<int>>> dataStore;
void storeSidePrime(int N)
{
    sidePrime.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j += 2)
        {
            if (pir_set.count(j + i))
            {
                sidePrime[i].insert(j);
            }
        }
    }
    int i = 0;
    for (auto outer : sidePrime)
    {
        cout << i++ << "--> ";
        for (auto it : outer)
            cout << it << " ";
        puts("");
    }
}
bool checker(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i += 2)
    {
        if (!pir_set.count(vec[i] + vec[i + 1]))
            return false;
        if (!pir_set.count(vec[i + 1] + vec[i + 2]))
            return false;
    }
    return true;
}
void store();
int main()
{
    freopen("input.txt", "r", stdin);
    storeSidePrime(16);
    store();
    cout << pir_set.count(4) << endl;
    int n;
    while (scanf("%d", &n) != EOF)
    {
    }
}
void store()
{
    dataStore[2] = {{1, 2}};
    dataStore[4] = {{1, 2, 3, 4}};
    dataStore[6] = {
        {1, 4, 3, 2, 5, 6},
        {1, 6, 5, 2, 3, 4}};
    dataStore[8] = {
        {1, 2, 3, 8, 7, , 5, 6, 7, 4},
        {1, 2, 5, 8, 3, 4, 7, 6},
        {1, 4, 7, 6, 5, 8, 3, 2},
        {1, 6, 7, 4, 3, 8, 5, 2},
    };
    dataStore[10] = {
        {1, 2, 3, 8, 5, 6, 7, 4},
        {1, 2, 5, 8, 3, 4, 7, 6},
        {1, 4, 7, 6, 5, 8, 3, 2},
        {1, 6, 7, 4, 3, 8, 5, 2},
    };
}