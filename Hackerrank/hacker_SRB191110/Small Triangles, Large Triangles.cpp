#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;

double size(double a, double b, double c)
{
    double P = (a + b + c) / 2;
    return sqrt(P * (P - a) * (P - b) * (P - c));
}
int comp(triangle a, triangle b)
{
    return size(a.a, a.b, a.c) > size(b.a, b.b, b.c);
}

void sort_by_area(triangle *tr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (comp(tr[i], tr[j]))
            {
                triangle temp;
                temp = tr[i];
                tr[i] = tr[j];
                tr[j] = temp;
            }
        }
    }
    //puts("");
}
int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}