#include <bits/stdc++.h>
using namespace std;
#define Size 1009
typedef pair<int, int> ppi;
string str[Size];
queue<ppi> Q;
int row, clm;
int stage[Size][Size], final_stage[Size][Size];
bool mark[Size][Size];

bool is_go(int x, int y) {
    if(x>=0 && x<row && y>=0 && y<clm) {
        if(str[x][y]=='.') return true;
    }
    return false;
}
void bfs(int x, int y) {
    int X[] = {-1, 0, 1, 0};
    int Y[] = {0, 1, 0, -1};
    mark[x][y] = 1;
    Q.push( make_pair(x, y) );
    while(!Q.empty()) {
        ppi now = Q.front();
        Q.pop();
        for(int k=0; k<4; k++) {
            x = now.first+X[k];
            y = now.second+Y[k];
            if(is_go(x, y) && !mark[x][y]) {
                mark[x][y] = 1;
                stage[x][y] = stage[now.first][now.second]+1;
                Q.push( make_pair(x, y) );
            }
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);

    int K, x, y;
    cin>>row>>clm>>K;
    for(int i=0; i<row; i++) {
        cin>>str[i];
    }
    while(K--) {
        cin>>x>>y;
        x--, y--;
        mark[x][y]=1;
        Q.push(make_pair(x, y));
    }

    bfs(x, y);
    int ans = 0;
    for(x=0; x<row; x++) {
        for(y=0; y<clm; y++) {
            if(str[x][y]=='.') {
                ans += stage[x][y];
            }
        }
    }
    cout<<ans<<endl;
}
