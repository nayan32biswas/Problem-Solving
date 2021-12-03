#include <bits/stdc++.h>
using namespace std;
int n;
int cost(int t, int c){
    return ((n/t)+(n%t>0))*c;
}
int main()
{
    int test, A, B, C;
    scanf("%d", &test);
    while(test--){
        scanf("%d%d%d%d", &n, &A, &B, &C);
        printf("%d\n", min(cost(2, A), min(cost(4, B), cost(50, C))));
    }
}
