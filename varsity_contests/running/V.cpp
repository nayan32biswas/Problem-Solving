#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
vector<ppi>totalDiv;
void storeDivisors(int n)
{
    totalDiv.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * i <= n; j++)
            totalDiv[(i * j)].second++;
    }
    for(int i=0; i<totalDiv.size(); i++)totalDiv[i].first = i;
}
bool compare(ppi x, ppi y)
{
    if (x.second<y.second || (x.second==y.second && x.first>y.first))
        return true;
    return false;
}
int main(){
    // freopen("input.txt", "r", stdin);
    storeDivisors(1000);
    sort(totalDiv.begin(), totalDiv.end(), compare);
    // for(int i=0; i<20; i++)cout<<i<<" "<<totalDiv[i].first<<" "<<totalDiv[i].second<<endl;puts("");
    // for(int i=1000; i>=980; i--)cout<<i<<" "<<totalDiv[i].first<<" "<<totalDiv[i].second<<endl;puts("");
    int test, n;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n",t, totalDiv[n].first);
    }
}