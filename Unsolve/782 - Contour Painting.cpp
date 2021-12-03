#include <bits/stdc++.h>
using namespace std;
bool visite[35][90];
char state[35][90];
int clm, row;

void interior(int i, int j) {
    if(i<0 || j<0 || j>clm || i>=row) return;
    if(visite[i][j] || state[i][j]=='X') return;

    if(state[i-1][j]=='X' || state[i][j-1]=='X' || state[i][j+1]=='X' || state[i+1][j]=='X')
        state[i][j]='#';
    visite[i][j] = 1;

    interior(i-1, j);
    interior(i, j-1);
    interior(i, j+1);
    interior(i+1, j);
    return;
}

int main()
{
    freopen("graph.txt", "r", stdin);
    int test, i, j, len;
    bool ck;
    scanf("%d", &test);
    getchar();
    for(int t=0; t<test; t++){
        row=0, i=0;
        ck = false;
        memset(visite, 0, sizeof(visite));
        memset(state, 0, sizeof(state));

        while(gets(state[row])){
            len = strlen(state[row]);
            clm = max(clm, len);
            if(state[row][0]=='_') break;
            if(!ck){
                for(j=0; j<len; j++)if(state[row][j]=='*'){
                    i = row; ck = true;
                    break;
                }
            }
            row++;
        }row++;

        state[i][j] = ' ';
        interior(i, j);
        for(i=0; i<row; i++){
            for(j=0, len=0; j<=clm; j++)if(state[i][j]==35){len=j;}
            if(len)for(j=0; j<len; j++)if(!state[i][j])state[i][j]=' ';
        }
        if(!t){if(state[0][0]!=0)puts(state[0]);
            for(i=1; i<row; i++)puts(state[i]);}
        else for(i=0; i<row; i++)puts(state[i]);
        //for(i=0;i<row;i++){for(j=0;j<=clm;j++)printf("%3d",state[i][j]);puts("");}puts("");
    }
    return 0;
}
