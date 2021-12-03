#include <bits/stdc++.h>
using namespace std;
char s[50][100], c, X;
int len[50], line;
bool vis[50][100];
void flodfill(int i, int J)
{
    if(s[i][J]==X || J>=len[i] || i<1 || J<1 || i>=line) return;
    if(vis[i][J]==true) return;
    s[i][J] = c;
    vis[i][J] = true;
    flodfill(i-1, J);
    flodfill(i, J-1);
    flodfill(i, J+1);
    flodfill(i+1, J);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, J;
    while(gets(s[0])){
        line = 1;
        memset(vis, 0, sizeof(vis));
        memset(len, 0, sizeof(len));
        while(gets(s[line])){
            if(s[line][0]=='_') break;
            len[line] = strlen(s[line]);
            line++;
        }
        for(i=0; s[0][i]; i++) {
            if(s[0][i]!=' '){
                X = s[0][i];
                break;
            }
        }
        for(i=1; i<line; i++) {
            for(J=0; J<len[i]; J++) {
                c = s[i][J];
                if(c!=' ' && c!=X && vis[i][J]==false){
                    flodfill(i, J);
                }
            }
        }
        line++;
        for(i=0; i<line; i++) {
            puts(s[i]);
        }
    }
    return 0;
}
