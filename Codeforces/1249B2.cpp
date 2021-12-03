#include <bits/stdc++.h>
using namespace std;
#define Size 200009
int arr[Size], ans[Size];
void find_ans(int pos)
{
    int child = pos, coun = 1;
    stack<int>stk;
    stk.push(pos);
    
    while (arr[pos] != child)
    {
        coun++;
        pos = arr[pos];
        stk.push(pos);
    }
    while(!stk.empty()){
        ans[stk.top()]= coun;
        stk.pop();
    }
}
void solve()
{
    int n;
    scanf("%d", &n);
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++){
        if(!ans[i]){
            find_ans(arr[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        solve();
    }

    return 0;
}