#include <bits/stdc++.h>
using namespace std;
#define Size 105
string stage[Size];
int row, clm;
bool isValid(int x, int y) {
    return x>=0 && x<row && y>=0 && y<clm && stage[x][y]=='*';
}
bool valid(int time, int x, int y) {
    int coun=0;
    if(isValid(x, y-1)) coun++;
    if(isValid(x, y+1)) coun++;
    if(isValid(x-1, y))coun++;
    if(isValid(x+1, y)) coun++;
    if(isValid(x-1, y-1)) coun++;
    if(isValid(x-1, y+1)) coun++;
    if(isValid(x+1, y-1)) coun++;
    if(isValid(x+1, y+1)) coun++;
    if(coun==time)
    return true;
    puts("NO");
    return false;

}
int main() {
    //freopen("input.txt", "r", stdin);

    cin>>row>>clm;
    for(int i=0; i<row; i++) {
        cin>>stage[i];
    }
    for(int i=0; i<row; i++) {
        for(int j=0; j<clm; j++) {
            if(stage[i][j]=='.') {
                if(valid(0, i, j)==false)
                    return 0;
            } else if(stage[i][j]!='*') {
                if(valid((stage[i][j]-'0'), i, j)==false)
                    return 0;
            }
        }
    }
    puts("YES");
    return 0;
}

