#include <bits/stdc++.h>
using namespace std;
#define Size 105
int row, k;
string stage[Size];
bool isValid(int x, int y) {
    return x>=0 && y>=0 && x<row && y<row && stage[x][y]=='.';
}
bool side(int x, int lo) {
    for(int hi=lo+k; lo<hi; lo++) {
        if(!isValid(x, lo)) {
            return false;
        }
    }
    return true;
}
bool tower(int lo, int y) {
    for(int hi=lo+k; lo<hi; lo++) {
        if(!isValid(lo, y)) {
            return false;
        }
    }
    return true;
}
int Find(int x, int y) {
    int ans = 0;
    for(int lo = y-k+1; lo<=y; lo++) {
        if(side(x, lo)==true) {
            ans++;
        }
    }
    for(int lo = x-k+1; lo<=x; lo++) {
        if(tower(lo, y)==true) {
            ans++;
        }
    }
    return ans;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int Max=0, X=0, Y=0;
    cin>>row>>k;
    for(int i=0; i<row; i++) {
        cin>>stage[i];
    }
    for(int i=0; i<row; i++) {
        for(int j=0; j<row; j++) {
            if(stage[i][j]=='.') {
                int ans = Find(i, j);
                if(ans>Max) {
                    Max = ans;
                    X = i;
                    Y = j;
                }
            }
        }
    }
    cout<<X+1<<" "<<Y+1<<endl;
    return 0;
}
