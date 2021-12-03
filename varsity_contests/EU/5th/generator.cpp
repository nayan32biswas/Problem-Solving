#include <bits/stdc++.h>
using namespace std;
long long int Find(long long int n)
{
    return random() % n + 2;
}
int main()
{
    srand(time(NULL));
    freopen("input5.txt", "w", stdout);
    long long T, n;
    cin >> T>>n;
    cout << T << endl;
    for (int i = 0; i < T; i++)
    {
        cout << Find(n) << endl;
    }
    return 0;
}