#include <bits/stdc++.h>
using namespace std;
#define Size 505
char stage[Size][Size];
int R[] = {-1, 0, 1, 0};
int C[] = {0, 1, 0, -1};
int row, clm;
bool is_true(int x, int y) {
    return x<row && y<clm && x>=0 && y>=0;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int x=-1, y=-1;
    cin>>row>>clm;
    for(int i=0; i<row; i++) {
        scanf("%s", stage[i]);
    }
    for(int i=0; i<row; i++) {
        for(int j=0; j<clm; j++) {
            if(stage[i][j]=='S') {
                for(int k=0; k<4; k++) {
                    x = i+R[k];
                    y = j+C[k];
                    if(is_true(x, y) && stage[x][y]=='W') {
                        puts("No");
                        return 0;
                    }
                }
            } else if(stage[i][j]=='.')
                stage[i][j] = 'D';
        }
    }
    puts("Yes");
    for(int i=0; i<row; i++) {
        printf("%s\n", stage[i]);
    }
    return 0;
}
