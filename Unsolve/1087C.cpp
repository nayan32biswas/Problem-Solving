#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
#define Size 1003
int row, col;
bool mark[Size][Size];

bool isValid(int x, int y)
{
    return x >= 0 && x < row && y >= 0 && y < col && !mark[x][y];
}
vector<ppi> findPath(map<ppi, ppi> &parents, ppi start, ppi End)
{
    vector<ppi> pathArray;
    ppi past = start;
    pathArray.push_back(past);
    while (past != End && parents[past] != End)
    {
        if (!parents[past])
            break;
        past = parents[past];
        pathArray.push_back(past);
    }
    pathArray.push_back(End);
    reverse(pathArray.begin(), pathArray.end());
    return pathArray;
}
map<ppi, ppi> bfs(ppi start)
{
    queue<ppi> Q;
    Q.push(start);
    map<ppi, ppi> parents;
    int X[] = {-1, 0, 1, 0};
    int Y[] = {0, 1, 0, -1};
    ppi now;
    int x, y;
    while(!Q.empty()){
        now = Q.front();
        Q.pop();
        for(int i=0; i<4; i++){
            x = X[i]+now.first;
            y = Y[i]+now.second;
            if(isValid(x, y)){
                parents[now] = make_pair(x, y)
                Q.push(make_pair(x, y));
                mark[x][y] = 1;
            }
        }
    }
    return parents;
}
int main()
{
    map<ppi, ppi> parents;
    vector<ppi> A, B, C;
    ppi a, b, c;
    cin>>a.first>>a.second;
    cin>>b.first>>b.second;
    cin>>c.first>>c.second;

    row = col = max(max(max(a.first, a.second), max(b.first, b.second)), max(c.first, c.second));
    parents = bfs(a);
    A = findPath(parents, a, b);
    for(auto it : A){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}