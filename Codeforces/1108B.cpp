#include <bits/stdc++.h>
using namespace std;
map<int, int> coun;
void show()
{
    for (auto it : coun)
    {
        cout << it.first << " " << it.second << endl;
    }
    puts("");
}
void removeD(int Max)
{

    for (int i = 2; i * i <= Max; i++)
    {
        if (Max % i == 0)
        {
            coun[i]--;
            if(i*i!=Max){
                coun[Max / i]--;
            }
        }
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int n, x, Max = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        coun[x]++;
        if (x > Max)
        {
            Max = x;
        }
    }
    // show();
    removeD(Max);
    coun[Max]--;
    // show();

    cout<<Max<<" ";
    Max = 0;
    for (auto it : coun)
    {
        if (it.second)
        {
            Max = it.first;
        }
    }
    cout << Max << endl;
    return 0;
}