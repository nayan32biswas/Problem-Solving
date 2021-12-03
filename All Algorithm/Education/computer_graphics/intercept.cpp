#include <bits/stdc++.h>
using namespace std;
void set_pixel(int x, int y)
{
    printf("%d %d\n", x, y);
}
void intercept(int x1, int y1, int x2, int y2)
{
    int x = x1, y = y1;
    double m = double(y2 - y1) / (x2 - x1);
    double b = y - m * x;
    set_pixel(x, y);
    if (m > 1)
    {
        while (y < y2)
        {
            y++;
            x = floor(((y - b) / m) + 0.5);
            set_pixel(x, y);
        }
    }
    else
    {
        while (x < x2)
        {
            x++;
            y = floor((b + m * x) + 0.5);
            set_pixel(x, y);
        }
    }
}
int main()
{
    intercept(0, 0, 6, 3);
    return 0;
}