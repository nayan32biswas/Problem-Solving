#include <bits/stdc++.h>
using namespace std;
struct data{
    int x, y, z;
    bool operator <(const data &t)const{
        return z<t.z;
    }
}value;
vector<data>graph;
int Set[200009];

int Check(int r){
    if(Set[r]==r) return r;
    else Set[r] = Check(Set[r]);
    return Set[r];
}
int mst(int node, int len){

    int i, one, two, sum, coun;
    sort(graph.begin(), graph.end());
    for(i=0; i<=node; Set[i]=i, i++);

    for(i=0, sum=0, coun=0; i<len; i++){
        one = Check(graph[i].x);
        two = Check(graph[i].y);
        if(one!=two){
            coun++;
            sum+=graph[i].z;
            Set[one] = two;
            if(node==coun) return sum;
        }
    }
    return sum;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, i;
    unsigned sum, Min;
    while(scanf("%d%d", &m, &n) && (m && n)){
        graph.clear();
        memset(Set, 0, sizeof(Set));
        for(i=0, sum=0; i<n; i++){
            scanf("%d%d%d", &value.x, &value.y, &value.z);
            sum+=value.z;
            graph.push_back(value);
        }

        Min = mst(m, n);
        printf("%d\n", sum-Min);
    }
}
