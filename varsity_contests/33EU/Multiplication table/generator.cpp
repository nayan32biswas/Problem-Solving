#include <bits/stdc++.h>
using namespace std;
long long int Find(long long int low, long long int hi)
{
    return random() % hi + low;
}
int main()
{
    srand(time(NULL));
    freopen("input.txt", "w", stdout);
    int test;
    cin >> test;
    cout << test << endl;
    for (int i = 1; i <= test; i++)
    {
        cout << i << endl;
    }
}