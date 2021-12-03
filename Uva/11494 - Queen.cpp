#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int x, y, x1, y1, dx, dy;
    while(scanf("%d%d%d%d", &x, &y, &x1, &y1)!=EOF) {
        if(!x && !y && !x1 && !y1) break;

        dx = abs(x-x1);
        dy = abs(y-y1);

        if(!dx && !dy) puts("0");
        else if(dx==dy || !dx ||!dy) puts("1");
        else puts("2");
    }
    return 0;
}
