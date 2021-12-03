#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VECT;
typedef map<VECT, string> MAP;
MAP visit;
queue<VECT> Q;
string path;
inline void push(VECT& v, string& path, char c) {
    if(!visit.count(v)) {
        Q.push(v);
        visit[v] = path+c;
    }
}
void BFS(int gard) {
    int i;
    VECT now, next;
    for(i=1; i<gard; now.push_back(i), i++);
    now.push_back(0);
    visit[now]="";
    Q.push(now);
    while(!Q.empty()){
        now = Q.front(); Q.pop();
        path = visit[now];
        for(i=0; i<gard && now[i]; i++);
        if(i%3!=2){
            next = now;
            swap(next[i], next[i+1]);
            push(next, path, 'l');
        }
        if(i%3){
            next = now;
            swap(next[i], next[i-1]);
            push(next, path, 'r');
        }
        if(i>2){
            next = now;
            swap(next[i], next[i-3]);
            push(next, path, 'd');
        }
        if(i<6){
            next = now;
            swap(next[i], next[i+3]);
            push(next, path, 'u');
        }
    }
    for(MAP::iterator it=visit.begin(); it!=visit.end(); it++)
        reverse(it->second.begin(), it->second.end());
}

int main() {
    freopen("input.txt", "r", stdin);
    BFS(9);
    int i, test;
    VECT ans;
    string input;
    scanf("%d", &test);
    getchar();
    while(test--) {
        getchar();
        getline(cin, input);
        ans.clear();
        for(i=0; input[i]; i++)if(input[i]!=' '){
            if(input[i]=='x') ans.push_back(0);
            else ans.push_back(input[i]-48);
        }
        if(visit.count(ans)){
            path = visit[ans];
            cout<<path<<endl;
        }
        else puts("unsolvable");
        if(test) puts("");
    }
    return 0;
}
/**
#include <bits/stdc++.h>
using namespace std;
typedef map<string, string> MAP;
MAP visit;
queue<string> Q;
inline void push(string& v, string& path, char c) {
    if(!visit.count(v)) {
        Q.push(v);
        visit[v] = path+c;
    }
}
void BFS(int gard) {
    int i;
    string now="12345678x", next, path;

    visit[now]="";
    Q.push(now);

    while(!Q.empty()){
        now = Q.front(); Q.pop();
        path = visit[now];
        for(i=0; i<gard && now[i]!='x'; i++);
        if(i%3!=2){
            next = now;
            swap(next[i], next[i+1]);
            push(next, path, 'l');
        }
        if(i%3){
            next = now;
            swap(next[i], next[i-1]);
            push(next, path, 'r');
        }
        if(i>2){
            next = now;
            swap(next[i], next[i-3]);
            push(next, path, 'd');
        }
        if(i<6){
            next = now;
            swap(next[i], next[i+3]);
            push(next, path, 'u');
        }
    }
    for(MAP::iterator it=visit.begin(); it!=visit.end(); it++)
        reverse(it->second.begin(), it->second.end());
}

int main() {
    freopen("input.txt", "r", stdin);
    BFS(9);
    int i, test;
    string ans, path, input;
    scanf("%d", &test);
    getchar();
    while(test--) {
        getchar();
        getline(cin, input);
        ans.clear();
        for(i=0; input[i]; i++)if(input[i]!=' '){
            ans+=input[i];
        }
        if(visit.count(ans)){
            path = visit[ans];
            cout<<path<<endl;
        }
        else puts("unsolvable");
        if(test) puts("");
    }
    return 0;
}
*/
