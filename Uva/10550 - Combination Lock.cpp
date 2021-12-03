#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a, b, c, d, ans;
    while(scanf("%d%d%d%d", &a, &b, &c, &d)==4 & (a || b || c || d)) {
        ans = (a-b+40)%40 + (c-b+40)%40 + (c-d+40)%40;
        printf("%d\n", (ans+120)*9);
    }
    return 0;
}
