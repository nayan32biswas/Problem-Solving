#include <bits/stdc++.h>
using namespace std;
#define Size 102
int mark[Size];
map<int, int>inDegree;
map<string, int>Map;
map<int, string>Map1;
string A, B;
int N, M, test=0;
vector< int >ans, graph[Size];
void Find() {
    bool check = true;
    while(check) {
        check = false;
        for(int i=1; i<=N; i++){
            if(!mark[i] && !inDegree[i]) {
                ans.push_back(i);
                check = true;
                mark[i] = true;
                for(auto it : graph[i])
                    inDegree[it]--;
                i=0;
            }
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    while(cin>>N) {

        Map.clear();
        Map1.clear();
        inDegree.clear();
        ans.clear();
        memset(mark, 0, sizeof(mark));
        for(int i=0; i<=N; i++)
            graph[i].clear();

        for(int i=1; i<=N; i++) {
            cin>>A;
            Map[A] = i;
            Map1[i] = A;
        }

        cin>>M;
        for(int i=0; i<M; i++) {
            cin>>A>>B;
            graph[Map[A]].push_back(Map[B]);
            inDegree[Map[B]]++;
        }

        Find();
        printf("Case #%d: Dilbert should drink beverages in this order:", ++test);
        for(auto it : ans) {
            cout<<" "<<Map1[it];
        }
        puts(".\n");
    }
    return 0;
}
