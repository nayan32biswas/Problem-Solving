#include <bits/stdc++.h>
#define Limit 100
using namespace std;
int dis[Limit];
bool visit[Limit];
vector<int>vectr[Limit];
int BFS(int N, int M);
int main()
{
    freopen("input.txt", "r", stdin);
    int x, y, node, edge, N, M;
    cin>>node>>edge;
    for(int i=0; i<edge; i++){
        cin>>x>>y;
        vectr[x].push_back(y);
        vectr[y].push_back(x);
        /*This in a undiracted group*/
    }
    cin>>N>>M;
    cout<<"Distance form N to M = "<<BFS(N,M)<<endl;
    return 0;
}
int BFS(int N, int M)
{
    queue<int>Q;
    int pos, temp, siz;
    Q.push(N);
    visit[N]=1;
    dis[N]=0;
    while(!Q.empty()){
        pos=Q.front();
        Q.pop();
        siz = vectr[pos].size();
        /*This siz represent how many node connected with this node*/
        for(int i=0; i<siz; i++){
            /*This loop mark all connected node*/
            temp=vectr[pos][i];
            if(!visit[temp]){
                visit[temp]=1;
                Q.push(temp);
                dis[temp]=dis[pos]+1;
                if(temp==M) return dis[temp];
                /*When we found M node distance form N node the return the value*/
            }
        }
    }
    return 0;
}
