#include <bits/stdc++.h>
#define SIZ 55000
using namespace std;
struct abc{
    int a, b, c;
}graph[SIZ];

int ans[SIZ], line[SIZ];
int i, J, k, len;

int main()
{
    //freopen("input.txt", "r", stdin);
    while(scanf("%d%d%d", &graph[J].a, &graph[J].b, &graph[J].c)==3){
        for(i=graph[J].a; i<graph[J].c; i++)
            if(line[i] < graph[J].b) line[i]=graph[J].b;
        if(len<graph[J].c) len = graph[J].c;
        J++;
    }
    for(i=0, J=0, k=0; i<=len; i++){
        if(line[i] != J){
            ans[k++] = i;
            ans[k++] = line[i];
            J = line[i];
        }
    }
    for(i=0; i<k; i++){
        if(i)cout<<' ';
        printf("%d", ans[i]);
    }puts("");
    return 0;
}
