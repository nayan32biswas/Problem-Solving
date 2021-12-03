#include <bits/stdc++.h>
using namespace std;

map<string, vector<string> >graph;
map<string, bool>visite;
map<string, string>parents;

bool BFS(string x, string y) {
    int len, i;
    string temp;
    queue<string>Q;
    parents.clear();
    visite.clear();
    Q.push(x);
    visite[x]=1;
    while(!Q.empty()) {
        x = Q.front(); Q.pop();
        len = graph[x].size();
        for(i=0; i<len; i++) {
            temp = graph[x][i];
            if(!visite[temp]) {
                visite[temp] = 1;
                parents[temp] = x;
                Q.push(temp);
                if(temp==y) {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int edge, test=0;
    string x, y;
    while(scanf("%d\n", &edge)==1) {
        if(test++) puts("");
        graph.clear();

        while(edge--) {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        cin>>x>>y;
        if(BFS(x, y)==false){
            puts("No route");
        }
        else {
            vector<string>ans;
            string temp=y;
            ans.push_back(temp);
            while(temp!=x) {
                temp = parents[temp];
                ans.push_back(temp);
            }
            //reverse(ans.begin(), ans.end());
            int len = ans.size();
            for(int i=len-1; i>0; i--) {
                cout<<ans[i]<<' '<<ans[i-1]<<endl;
            }
        }
    }
}
