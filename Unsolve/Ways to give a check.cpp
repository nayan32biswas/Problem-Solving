#include <bits/stdc++.h>
using namespace std;
#define Size 8
string stage[Size];

bool valid(int x, int y) {
    return x>=0 && y>=0 && x<8 && y<8;
}
bool nnn(int x, int y) {
    int R[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int C[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    for(int k=0; k<8; k++) {
        int i=x+R[k], j=y+C[k];
        if(valid(i, j) && stage[i][j]=='k')
            return true;
    }
    return false;
}
bool bbb(int x, int y) {
    int R[] = {-1, -1, 1, 1};
    int C[] = {-1, 1, -1, 1};
    for(int k=0; k<4; k++){
        for(int i=R[k]+x, j=C[k]+y; valid(i, j); i+=R[k], j+=C[k]) {
            if(stage[i][j]=='#')
                continue;
            if(stage[i][j]=='k')
                return true;
            break;
        }
    }
    return false;
}
bool rrr(int x, int y) {
    int R[] = {0, 1, 0, -1};
    int C[] = {-1, 0, 1, 0};
    for(int k=0; k<4; k++){
        for(int i=R[k]+x, j=C[k]+y; valid(i, j); i+=R[k], j+=C[k]) {
            if(stage[i][j]=='#')
                continue;
            if(stage[i][j]=='k')
                return true;
            break;

        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
    while(test--) {
        for(int i=0; i<Size; i++)
            cin>>stage[i];
        int way = 0;
        for(int j=0, i=1; j<Size; j++) {
            if(stage[i-1][j]=='#' && stage[i][j]=='P') {
                stage[i][j] = '#';
                stage[i-1][j] = 'P';
                if(bbb(i-1, j))
                    way+=2;
                if(rrr(i-1, j))
                    way+=2;
                way += nnn(i-1, j);
            }
        }
        for(int j=0; j<Size; j++){
            for(int i=0; i<Size; i++){
                if(stage[i][j]=='B') way += bbb(i, j);
                else if(stage[i][j]=='R') way += rrr(i, j);
                else if(stage[i][j]=='Q') way += bbb(i, j), way += rrr(i, j);
            }
        }
        cout<<way<<endl;
    }
    return 0;
}
