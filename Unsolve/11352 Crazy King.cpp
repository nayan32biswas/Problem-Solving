#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
#define Size 105
#define Max INT_MAX
/// for king
int RRR[] = {0, 0, 1, -1, -1, 1, 1, -1};
int CCC[] = {1, -1, 0, 0, -1, 1, -1, 1};
/// for knight
int rrr[] = {-1, -1, -2, -1, 1, 2, 2, 1};
int ccc[] = {-2, -1, 1, 2, -2, -2, 1, 2};
int row, clm;
bool is_valid(int x, int y){
    return x>=0 && y>=0 && x<row && y<clm;
}

int mark[Size][Size];
char stage[Size][Size];
void bfs(queue<ppi> Q, ppi B){
    int x, y;
    ppi prev;
    while(!Q.empty()){
        prev = Q.front(); Q.pop();
        for(int i=0; i<8; i++){
            x = prev.first+RRR[i];
            y = prev.second+CCC[i];
            if(is_valid(x, y)){
                if(stage[x][y]=='.'){
                    stage[x][y] = 'X';
                    mark[x][y] = mark[prev.first][prev.second]+1;
                    Q.push(make_pair(x, y));
                }
                else if(x==B.first && y==B.second){
                    printf("Minimal possible length of a trip is %d\n", mark[prev.first][prev.second]);
                    return;
                }
            }
        }
    }
    puts("King Peter, you can't go now!");
}
int main()
{
    freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%d%d", &row, &clm);
        memset(mark, 0, sizeof(mark));
        queue<ppi> Q;
        ppi B;
        for(int i=0; i<row; i++){
            scanf("%s", stage[i]);
            for(int j=0; j<clm; j++){
                if(stage[i][j]=='A') Q.push(make_pair(i, j)), mark[i][j]=1;
                else if(stage[i][j]=='B') B = make_pair(i, j);
            }
        }

        for(int i=0; i<row; i++) cout<<stage[i]<<endl; puts("");

        for(int i=0; i<row; i++){
            int x, y;
            for(int j=0; j<clm; j++){
                if(stage[i][j]=='Z'){
                    for(int k=0; k<8; k++){
                        x = i+rrr[k];
                        y = j+ccc[k];
                        if(is_valid(x, y) && stage[x][y]=='.') stage[x][y] = 'X';
                    }
                }
            }
        }
        for(int i=0; i<row; i++) cout<<stage[i]<<endl; puts("\n\n");
        bfs(Q, B);
    }
}
