#include <bits/stdc++.h>
using namespace std;
struct node
{
    int left, mid, right;
};
vector<node> arr;
void show()
{
    for (auto it : arr)
    {
        printf("%d %d %d\n", it.left, it.mid, it.right);
    }
    puts("");
}
int main()
{
    freopen("input.txt", "r", stdin);
    int test, k, ans;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        ans = 0;
        scanf("%d", &k);
        arr.resize(++k);
        for (int i = 0; i < k; i++)
            scanf("%d", &arr[i].mid);
        for (int i = 0, Max = 0; i < k; i++)
        {
            Max = max(Max, arr[i].mid);
            arr[i].left = Max;
        }
        for (int i = k - 1, Max = 0; i >= 0; i--)
        {
            Max = max(Max, arr[i].mid);
            arr[i].right = Max;
        }
        for (auto it : arr)
        {
            if (it.left > it.mid && it.mid < it.right)
            {
                cout<<it.mid<<" ";
                ans++;
            }
        }
        puts("");
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}