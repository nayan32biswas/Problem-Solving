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
    long long test;
    cin>>test;
    cout << test << endl;
    for (long long i = 0; i < test; i++)
        cout << Find(1, 100000000000) << endl;
}