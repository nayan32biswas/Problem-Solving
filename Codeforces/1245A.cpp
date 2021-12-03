#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test, a, b;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d%d", &a, &b);
        if(__gcd(a, b)==1)puts("Finite");
        else puts("Infinite");
    }
    return 0;
}