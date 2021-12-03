#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
list<int> temp;
list<list<int>> ans;
map<list<int>, bool> mark;
int n;
void show()
{
    for (auto it : ans)
    {
        bool xxx = 0;
        for (auto it1 : it)
        {
            if(xxx)printf("+");
            xxx=1;
            printf("%d", it1);
        }
        puts("");
    }
}
void each_case(int index, int t)
{
    if (t == 0)
    {
        if (!mark[temp])
        {
            ans.push_back(temp);
            mark[temp] = true;
        }
        return;
    }
    if (index >= n)
    {
        return;
    }
    for (int i = index; i < n; i++)
    {
        if (t - arr[i] >= 0)
        {
            temp.push_back(arr[i]);
            each_case(i + 1, t - arr[i]);
            temp.pop_back();
        }
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int t;
    while (scanf("%d%d", &t, &n) and n)
    {
        temp.clear();
        ans.clear();
        mark.clear();
        arr.resize(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        each_case(0, t);
        printf("Sums of %d:\n", t);
        if(mark.size()){
            show();
        }
        else{
            puts("NONE");
        }
    }
    return 0;
}