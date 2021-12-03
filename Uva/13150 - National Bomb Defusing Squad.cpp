#include <bits/stdc++.h>
using namespace std;
#define Size 3000
#define MAX INT_MAX
int dis(int x, int y, int x1, int y1){
    x = abs(x-x1);
    y = abs(y-y1);
    return ceil(sqrt(x*x + y*y));
}
pair<int, int>arr[Size];
vector<int>Dis[Size];
int position(int i, int R){
    int pos = upper_bound(Dis[i].begin(), Dis[i].end(), R)-Dis[i].begin()-1;
    if(pos<0) return 0;
    while(Dis[i][pos]>R) pos--;
    pos++;
    return pos<<1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int N, Q, R, total, x, y, start, t=0;
    while(cin>>N>>Q && N && Q){
        for(int i=0; i<N; i++) Dis[i].clear();
        for(int i=0; i<N; i++)scanf("%d%d", &arr[i].first, &arr[i].second);
        for(int i=0; i<N; i++){
            x = arr[i].first, y = arr[i].second;
            for(int j=i+1; j<N; j++){
                Dis[i].push_back(dis(x, y, arr[j].first, arr[j].second));
            }
        }
        for(int i=0; i<N; i++){
            sort(Dis[i].begin(), Dis[i].end());
            Dis[i].push_back(MAX);
        }
        for(int i=0; i<Q; i++){
            scanf("%d", &R);
            total = N;
            for(int j=0; j<N; j++)total+=position(j, R);
            printf("%.2lf\n",(double)total/N);
        }
        puts("");
    }
    return 0;
}
