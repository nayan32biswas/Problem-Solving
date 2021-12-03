#include <bits/stdc++.h>
using namespace std;
#define Size 209
typedef pair<int, string> ppi;
vector<int>graph[Size];
map<string, int>hashcode;
vector< ppi >input;
int mark[Size];
bool CHECK(int x, int y) {
    int len = input[x].first, len1 = input[y].first;
    int dif = abs(len-len);
    if(dif>0) return false;
    string s = input[x].second, s1 = input[y].second;
    for(int i=0; i<len; i++) {
        if(s[i]!=s1[i]) dif++;
        if(dif>1) return false;
    }
    return true;
}
void BFS(int sorce, int dasti) {
    if(sorce==dasti) {
        puts("0");
        return;
    }
    memset(mark, 0, sizeof(mark));
    queue<int>Q;
    Q.push(sorce);
    mark[sorce] = 1;
    while(!Q.empty()) {
        int parents = Q.front();
        Q.pop();
        for(auto V : graph[parents]) {
            if(V==dasti) {
                printf("%d\n", mark[parents]);
                return;
            }
            if(!mark[V]) {
                mark[V] = mark[parents]+1;
                Q.push(V);

            }
        }
    }
    puts("-1");
}
bool cmp(ppi a, ppi b) {
    return a.first<b.first;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
    for(int t=0; t<test; t++) {
        string s, s1, str;
        int len = 0;
        hashcode.clear();
        for(int i=0; i<Size; i++) graph[i].clear();
        while(cin>>s && s!="*") {
            input.push_back(make_pair(s.size(), s));
            if(!hashcode[s]) hashcode[s] = len++;
        }
        sort(input.begin(), input.end(), cmp);
        int x, y, temp;
        for(int i=0; i<len; i++) {
            x = hashcode[input[i].second];
            temp = input[i].first;
            for(int j=i+1; j<len && temp==input[j].first; j++) {
                if(CHECK(i, j)) {
                    y = hashcode[input[j].second];
                    graph[x].push_back(y);
                    graph[y].push_back(x);
                }
            }
        }
        if(t) puts("");
        cin.ignore();
        while(getline(cin, str) && str!="") {
            int pos = str.find(" ");
            s = str.substr(0,pos);
            s1 = str.substr(pos+1,str.size());
            cout<<s<<" "<<s1<<" ";
            BFS(hashcode[s], hashcode[s1]);
        }
    }
}
