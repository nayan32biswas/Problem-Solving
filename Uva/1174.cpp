#include <bits/stdc++.h>
using namespace std;
#define Size 2005
struct node
{
    int x, y, w;
    bool operator<(const node &p) const
    {
        return w < p.w;
    }
} temp;
int mark[Size];
vector<node> graph;
int Find(int r)
{
    if (mark[r] == r)
        return r;
    return mark[r] = Find(mark[r]);
}
void karuskal(int n)
{
    int i, sum = 0, x, y;
    sort(graph.begin(), graph.end());
    for (i = 0; i <= n; i++)
        mark[i] = i;

    for (auto it : graph)
    {
        x = Find(it.x);
        y = Find(it.y);
        if (x != y)
        {
            mark[x] = y;
            sum += it.w;
        }
    }
    printf("%d\n", sum);
}
int main(){
    // freopen("input.txt", "r", stdin);
    int test, n, m;
    scanf("%d", &test);
    for(int t=0; t<test; t++){
        scanf("%d%d", &n, &m);
        graph.clear();
        map<string, int>temporarySet;
        int point=1;
        string a, b;

        for(int i=0; i<m; i++){
            cin>>a>>b;
            scanf("%d", &temp.w);
            if(temporarySet[a])
                temp.x = temporarySet[a];
            else
            {
                temporarySet[a] = point;
                temp.x = point;
                point++;
            }
            if(temporarySet[b])
                temp.y = temporarySet[b];
            else
            {
                temporarySet[b] = point;
                temp.y = point;
                point++;
            }
            graph.push_back(temp);
        }
        if(t)
            puts("");
        karuskal(n);
    }
}