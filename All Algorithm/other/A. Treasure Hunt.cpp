#include <bits/stdc++.h>
using namespace std;
int a, b;
bool one, two, three, four;
int main()
{
    freopen("input.txt", "r", stdin);
    int x1, x2, y1, y2, xn, yn;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf("%d%d", &a, &b);
    xn = a+x1;
    x1 = a-x1;
    yn = b+y1;
    y1 = b-y1;
    if(xn!=0) xn = x2%xn;
    else xn = 1;
    if(x1!=0) x1 = x2%x1;
    else x1 = 1;
    if(yn!=0) yn = x2%yn;
    else yn = 1;
    if(y1!=0) y1 = x2%y1;
    else y1 = 1;

    else puts("NO");

}
