#include <bits/stdc++.h>
using namespace std;
void set_pixel(int x, int y)
{
    printf("%d %d\n", x, y);
}
void dda(int x1, int y1, int x2, int y2)
{
    int x = x1, y = y1;
    double dx = (x2 - x1), dy = y2 - y1;
    if (dy / dx <= 1)
    {
        double m = dx / dy, xf = x;
        while (y <= y2)
        {
            x = floor(xf + 0.5);
            set_pixel(x, y);
            xf = xf + m;
            y++;
        }
    }
    else
    {
        double m = dy / dx, yf = y;
        while (x <= x2)
        {
            y = floor(yf + 0.5);
            set_pixel(x, y);
            x++;
            yf = yf + m;
        }
    }
}
int main()
{
    dda(0, 0, 6, 3);
    return 0;
}