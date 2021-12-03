#include <bits/stdc++.h>
using namespace std;
int get(int min, int max)
{
    return min + (rand() % static_cast<int>(max - min + 1));
}
void eachCase(int N, int Q)
{
    printf("%d\n", N);
    for (int i = 1; i < N; i++)
    {
        printf("%d %d\n", i, i + 1);
    }
    printf("%d\n", Q);
    for (int i = 0; i < Q; i++)
    {
        if (get(1, 2) & 1)
        {
            printf("1 %d %d\n", get(1, N), get(10000000, 100000000));
        }
        else
        {
            printf("2 %d\n", get(1, N));
        }
    }
}
int main()
{
    freopen("rand_input.txt", "w", stdout);

    int test = 10;
    printf("%d\n", test);
    for (int i = 0; i < test; i++)
    {
        eachCase(get(100000, 100000), get(100000, 100000));
    }
}