#include <bits/stdc++.h>
using namespace std;
#define Size 55
#define INF 99
typedef pair<int, int> ppi;
struct data {
    int north, south, west, east;
};

int row, clm;
data graph[Size][Size];
bool mark[Size][Size];

void print();
int Min(data temp);
void north(data &temp);
void south(data &temp);
void east(data &temp);
void west(data &temp);
bool is_go(int x, int y);
void bfs(int x, int y);

int main() {
    //freopen("input.txt", "r", stdin);
    while(scanf("%d%d", &row, &clm) && row) {
        memset(graph, true, sizeof(graph));
        memset(mark, 0, sizeof(mark));
        for(int i=0; i<row; i++) {
            for(int j=0; j<clm; j++) {
                scanf("%d", &mark[i][j]);
                graph[i][j].north=graph[i][j].south=graph[i][j].east=graph[i][j].west=INF;
            }
            graph[i][clm].north=graph[i][clm].south=graph[i][clm].east=graph[i][clm].west=INF;
        }
        int x, y, x1, y1;
        string str;
        scanf("%d%d%d%d", &x, &y, &x1, &y1);
        cin>>str;
        //x--, y--, x1--, y1--;
        if(x1<0 || y1<0 || x1>=row || y1>=clm){
            puts("-1");
            continue;
        }
        if(str=="north") {
            graph[x][y].north = 0;
            north(graph[x][y]);
        } else if(str=="south") {
            graph[x][y].south = 0;
            south(graph[x][y]);
        } else if(str=="east") {
            graph[x][y].east = 0;
            east(graph[x][y]);
        } else if(str=="west") {
            graph[x][y].west = 0;
            west(graph[x][y]);
        }
        bfs(x, y);
        //print();
        int ans = Min(graph[x1][y1]);
        if(ans==INF)
            ans = -1;
        printf("%d\n", ans);
    }
}
void bfs(int x, int y) {
    int north_R[] = {-1, -2, -3};
    int south_R[] = {1, 2, 3};
    int east_C[] = {1, 2, 3};
    int west_C[] = {-1, -2, -3};

    int coun=0;
    ppi now;
    queue<ppi>Que;
    Que.push(make_pair(x, y));

    int dis;

    while(!Que.empty()) {
        now = Que.front();
        Que.pop();
        coun++;
        /// for north
        dis = graph[now.first][now.second].north+1;
        y = now.second;
        for(auto it : north_R) {
            x = now.first+it;
            if(is_go(x, y)) {
                if(graph[x][y].north>dis) {
                    graph[x][y].north = dis;
                    Que.push(make_pair(x, y));
                    north(graph[x][y]);
                }
            } else
                break;
        }

        /// for south
        dis = graph[now.first][now.second].south+1;
        y = now.second;
        for(auto it : south_R) {
            x = now.first+it;
            if(is_go(x, y)) {
                if(graph[x][y].south>dis) {
                    graph[x][y].south = dis;
                    Que.push(make_pair(x, y));
                    south(graph[x][y]);
                }
            } else
                break;
        }


        /// for east
        dis = graph[now.first][now.second].east+1;
        x = now.first;
        for(auto it : east_C) {
            y = now.second+it;
            if(is_go(x, y)) {
                if(graph[x][y].east>dis) {
                    graph[x][y].east = dis;
                    Que.push(make_pair(x, y));
                    east(graph[x][y]);
                }
            } else
                break;
        }

        /// for west
        dis = graph[now.first][now.second].west+1;
        x = now.first;
        for(auto it : west_C) {
            y = now.second+it;
            if(is_go(x, y)) {
                if(graph[x][y].west>dis) {
                    graph[x][y].west = dis;
                    Que.push(make_pair(x, y));
                    west(graph[x][y]);
                }
            } else
                break;
        }
    }
    //cout<<coun<<endl;
}
void north(data &temp) {
    temp.south = min(temp.south, temp.north+2);
    temp.east = min(temp.east, temp.north+1);
    temp.west = min(temp.west, temp.north+1);
}
void south(data &temp) {
    temp.north = min(temp.north,temp.south+2);
    temp.east = min(temp.east,temp.south+1);
    temp.west = min(temp.west,temp.south+1);
}
void east(data &temp) {
    temp.north = min(temp.north,temp.east+1);
    temp.south = min(temp.south,temp.east+1);
    temp.west = min(temp.west,temp.east+2);
}
void west(data &temp) {
    temp.north = min(temp.north,temp.west+1);
    temp.south = min(temp.south,temp.west+1);
    temp.east = min(temp.east,temp.west+2);
}
bool is_go(int x, int y) {
    return x>0 && x<row && y>0 && y<clm && !mark[x][y] && !mark[x][y-1] && !mark[x-1][y-1] && !mark[x-1][y];
}
int Min(data temp) {
    return min(temp.north, min(temp.south, min(temp.east, temp.west)));
}
void print() {
    puts("");
    for(int i=0; i<row; i++) {
        for(int j=0; j<clm; j++) {
            printf("%2d%2d%2d%2d.", graph[i][j].west, graph[i][j].north, graph[i][j].south, graph[i][j].east);
        }
        puts("");
    }
}

