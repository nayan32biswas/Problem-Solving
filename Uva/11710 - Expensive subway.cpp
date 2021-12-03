#include <bits/stdc++.h>
using namespace std;
struct data{
    int from, to, wate;
}first;

bool cmp(data e1, data e2){ return (e1.wate < e2.wate);}
int disjoint[401];
vector<data>graph;
map<string, int>mark;

int finde(int s){
    if(s==disjoint[s]) return s;
    else return disjoint[s] = finde(disjoint[s]);
}
void MST(string sorce, int s, int c){
    sort(graph.begin(), graph.end(), cmp);
    int ans=0, x, y;
    s--;
    for(auto G:graph){
        x = finde(G.from);
        y = finde(G.to);
        if(x!=y){
            disjoint[x]=y;
            ans+=G.wate;
            s--;
        }
    }
    if(s) printf("Impossible\n");
    else printf("%d\n", ans);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int s, c;
    while(scanf("%d%d", &s, &c)==2 && s!=0){
        graph.clear();
        mark.clear();
        string x, y, sorce;
        for(int i=0; i<s; i++){
            cin>>x;
            mark[x]=i;
            disjoint[i]=i;
        }
        for(int i=0; i<c; i++){
            cin>>x>>y>>first.wate;
            first.from = mark[x];
            first.to = mark[y];
            graph.push_back(first);
        }
        cin>>sorce;
        MST(sorce, s, c);
    }
    return 0;
}
