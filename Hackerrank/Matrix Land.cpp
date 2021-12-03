#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
#define Size 509
int graph[Size][Size], mark[Size][mark], dis[Size][Size];
int row, clom;
int R[] = {0, 0, 1};
int C[] = {-1, 1, 0};
bool is_valid(int x, int y){
    return x>=0 && y>=0 && x<row && y<clom;
}
void bfs(){
    queue<ppi>Q;
    int x=0, y;
    for(int i=0; i<clom; i++){
        Q.push(make_pair(0, i));
    }
    ppi now;
    while(!Q.empty()){
        now = Q.front(); Q.pop();
        for(int k=0; k<3; k++){
            x = now.frist+R[k];
            y = now.second+C[k];
            if(is_valid(x, y)){
                if(!mark[x][y]){
                    dis[x][y] = dis[x][y]
                }
                mark[x][y]++;
            }
        }
    }
}
int main()
{
    int x;
    row = 0, clom=0;
    cin>>row>>clom;
    for(int i=0; i<row; i++){
        for(int j=0; j<clom; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    bfs();
    return 0;
}
