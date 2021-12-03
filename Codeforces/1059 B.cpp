#include <bits/stdc++.h>
using namespace std;
#define Size 1005
int n, m;
bool stage[Size][Size], mark[Size][Size];
int X[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int Y[] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool centerCheck(int x, int y) {
    return x>0 && y>0 && x<(n-1) && y<(m-1);
}
bool check(int x, int y) {
    return x>=0 && y>=0 && x<n && y<m;
}
bool Set(int x, int y) {
    if(centerCheck(x, y)==false)
        return false;
    int u, v;
    for(int i=0; i<8; i++) {
        u = x+X[i];
        v = y+Y[i];
        if(stage[u][v]==false || check(u, v)==false) {
            return false;
        }
    }
    for(int i=0; i<8; i++) {
        u = x+X[i];
        v = y+Y[i];
        mark[u][v] = true;
    }
    return true;
}
int main() {
    string str;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        cin>>str;
        for(int j=0; j<m; j++) {
            if(str[j]=='#') {
                stage[i][j] = true;
            }
        }
    }
    int I[] = {1, 1, 1, 0};
    int J[] = {1, 0, -1, 1};
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(stage[i][j]==true) {
                for(int k=0; k<4; k++){
                    if(Set(i+I[k], j+J[k])) break;
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mark[i][j] != stage[i][j]) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
