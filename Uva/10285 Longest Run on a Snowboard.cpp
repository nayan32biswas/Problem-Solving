#include <bits/stdc++.h>
using namespace std;
#define Size 105
struct node{
    int height, value;
    pair<int, int>axis;
    bool operator <(const node& T)const {
        if(value!=T.value)
            return value<T.value;
        return height<T.height;
    }
}now, temp;
int row, clm;
int area[Size][Size], wate[Size][Size];
priority_queue<node>Que;
bool is_go(int i, int j, int ii, int jj){
    return ii>=0 && jj>=0 && ii<row && jj<clm && area[i][j]>area[ii][jj];
}
void bfs(){
    memset(wate, 0, sizeof(wate));
    int R[] = {0, 0, -1, 1};
    int C[] = {-1, 1, 0, 0};
    int ii, jj, ans = 0;
    while(!Que.empty()){
        now = Que.top(); Que.pop();
        for(int k=0; k<4; k++){
            ii = now.axis.first+R[k];
            jj = now.axis.second+C[k];

            if(is_go(now.axis.first, now.axis.second, ii, jj)){
                if(wate[ii][jj]<=wate[now.axis.first][now.axis.second]){
                    wate[ii][jj] = now.value+1;
                    ans = max(now.value+1, ans);

                    temp.axis.first = ii;
                    temp.axis.second = jj;
                    temp.height = area[ii][jj];
                    temp.value = wate[ii][jj];

                    Que.push(temp);
                }
            }
        }
    }
    cout<<ans+1<<endl;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
    while(test--){
        string name;
        cin>>name>>row>>clm;
        for(int i=0; i<row; i++){
            now.value = 0;
            for(int j=0; j<clm; j++){
                scanf("%d", &area[i][j]);
                now.axis.first = i;
                now.axis.second = j;
                now.value = 0;
                Que.push(now);
            }
        }
        cout<<name<<": ";
        bfs();
    }
}
