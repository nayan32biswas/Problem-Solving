#include <bits/stdc++.h>
using namespace std;
bool isPrime[32];
void store()
{
    int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (auto it : prime)
        isPrime[it] = true;
}
int main()
{
    store();
    return 0;
}