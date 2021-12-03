#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, test;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d%d", &a, &b);
        printf("Case %d: %d\n", t, 19+(4*(abs(a-b)+a)));
    }
    return 0;
}
