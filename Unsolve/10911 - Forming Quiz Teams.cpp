#include <bits/stdc++.h>
using namespace std;
#define Size 16
typedef pair< double, int> pairD;
typedef pair<int, int> pairI;
#define distance(x, y) (sqrt(pow(abs(x.first-y.first), 2)+pow(abs(x.second-y.second), 2)))
vector<pairD>graph[Size];
bool mark[Size];
pairI Find(int N);
double ans(int N);
int main() {
    //freopen("input.txt", "r", stdin);
    int N, x, y, t=1;
    vector<pairI>vec;
    char str[21];
    while(scanf("%d", &N) && N) {
        N = N<<1;
        vec.clear();
        for(int i=0; i<N; i++)
            graph[i].clear();
        for(int i=0; i<N; i++) {
            scanf("%s%d%d", str, &x, &y);
            vec.push_back(make_pair(x, y));
        }

        for(int i=0; i<N; i++) {
            double temp;
            for(int j=i+1; j<N; j++) {
                temp = distance(vec[i], vec[j]);
                graph[i].push_back(make_pair(temp, j));
                graph[j].push_back(make_pair(temp, i));
            }
        }
        for(int i=0; i<N; i++)
            sort(graph[i].begin(), graph[i].end());
        N = N>>1;

        printf("Case %d: ", t++);
        cout<<fixed<<setprecision(2)<<ans(N)<<endl;
    }
    return 0;
}
pairI dicresing(int N) {
    double Max = 0;
    int pos = -1;
    for(int i=0; i<N; i++) {
        if(mark[i]==0 && mark[graph[i][0].second]==0 && graph[i][0].first>Max) {
            Max = graph[i][0].first;
            pos = i;
        }
    }
    if(pos<0) return make_pair(-1, -1);
    return make_pair(pos, graph[pos][0].second);
}
pairI incresing(int N) {
    double Max = INT_MAX;
    int pos = -1;
    for(int i=0; i<N; i++) {
        if(mark[i]==0 && mark[graph[i][0].second]==0 && graph[i][0].first<Max) {
            Max = graph[i][0].first;
            pos = i;
        }
    }
    if(pos<0) return make_pair(-1, -1);
    return make_pair(pos, graph[pos][0].second);
}
double ans(int N) {
    double dicre = 0, incre = 0;
    memset(mark, 0, sizeof(mark));
    for(int i=0; i<N; i++) {
        pairI temp = dicresing(N<<1);
        if(temp.first>=0) {
            dicre += graph[temp.first][0].first;
            mark[temp.first] = 1;
            mark[temp.second] = 1;
        }
        else {
            dicre += 999999;
        }
    }
    memset(mark, 0, sizeof(mark));
    for(int i=0; i<N; i++) {
        pairI temp = incresing(N<<1);
        if(temp.first>=0) {
            incre += graph[temp.first][0].first;
            mark[temp.first] = 1;
            mark[temp.second] = 1;
        }
        else {
            incre += 999999;
        }
    }
    return min(dicre, incre);
}
