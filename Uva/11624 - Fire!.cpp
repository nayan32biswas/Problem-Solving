#include <bits/stdc++.h>
using namespace std;
#define Size 1005
typedef pair<int, int> ppi;
char stage[Size][Size];
int row, clm, visite[Size][Size];
bool answer(int x, int y){
    return x<0 || y<0 || x>=row || y>=clm;
}
bool is_valid(int x, int y){
    return x>=0 && y>=0 && x<row && y<clm;
}
bool is_maze(int x, int y){
    return is_valid(x, y) && stage[x][y]=='.';
}
bool is_fire(int x, int y){
    return is_valid(x, y) && stage[x][y]!='#' && stage[x][y]!='F';
}

void bfs(queue<ppi> Q){
    int x, y;
    ppi prev;
    int R[] = {0, 0, 1, -1};
    int C[] = {1, -1, 0, 0};
    while(!Q.empty()){
        prev = Q.front(); Q.pop();
        if(stage[prev.first][prev.second]=='F'){
            for(int i=0; i<4; i++){
                x = R[i]+prev.first;
                y = C[i]+prev.second;
                if(is_fire(x, y)){
                    Q.push(make_pair(x, y));
                    stage[x][y] = 'F';
                }

            }
        }
        else if(stage[prev.first][prev.second]=='J'){
            for(int i=0; i<4; i++){
                x = R[i]+prev.first;
                y = C[i]+prev.second;
                if(answer(x, y)){
                    printf("%d\n", visite[prev.first][prev.second]);
                    return;
                }
                if(is_maze(x, y)){
                    Q.push(make_pair(x, y));
                    stage[x][y] = 'J';
                    visite[x][y] = visite[prev.first][prev.second]+1;
                }
            }
        }

    }
    puts("IMPOSSIBLE");
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%d%d", &row, &clm);
        queue<ppi> Q;
        memset(visite, 0, sizeof(visite));

        for(int i=0; i<row; i++){
            scanf("%s", stage[i]);
            for(int j=0; stage[i][j]; j++){
                if(stage[i][j]=='F') Q.push(make_pair(i, j));
                else if(stage[i][j]=='J'){
                    Q.push(make_pair(i, j));
                    visite[i][j] = 1;
                }
            }
        }
        bfs(Q);
    }
}
