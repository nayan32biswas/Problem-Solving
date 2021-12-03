#include <bits/stdc++.h>
using namespace std;
#define Size 309
unsigned graph[Size][Size], dis[Size][Size];
int main() {
    //freopen("input.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>graph[i][j];
    memset(dis, -1, sizeof(dis));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<N; k++)
                dis[i][j] = min(dis[i][j], graph[i][k]+graph[k][j]);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(dis[i][j]!=graph[i][j])
                return puts("-1")*0;
    long long ans = 0;
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++) {
            bool ck = true;
            for(int k=0; k<N; k++)
                if((dis[i][j] == dis[i][k]+dis[k][j]) && (dis[i][j] != dis[i][k]) && (dis[i][j]!=dis[k][j])) {
                    ck = false;
                    break;
                }
            if(ck)
                ans += dis[i][j];
        }
    cout<<ans<<endl;
    return 0;
}
