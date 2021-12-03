#include <bits/stdc++.h>
using namespace std;
int X[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int Y[] = {-1, 1, 2, 2, 1, -1, -2, -2};
bool check(int x, int y){
    return x>0 && x<=8 && y>0 && y<=8;
}
int main(){
    //freopen("input.txt", "r", stdin);
    int test, x, y;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d%d", &x, &y);
        int ans = 0;
        for(int i=0; i<8; i++){
            if(check(x+X[i], y+Y[i])){
                ans++;
            }
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}

