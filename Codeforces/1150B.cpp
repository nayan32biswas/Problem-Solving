#include <bits/stdc++.h>
using namespace std;
vector<string>state;
int n;
bool check(int x, int y){
    return x>=0 && x<n && y>=0 && y<n && state[x][y]=='.';
}
bool find(){
    int space=0;
    cin>>n;
    state.resize(n);
    for(int i=0; i<n; i++){
        cin>>state[i];
        for(auto it : state[i])if(it=='.')space++;
    }
    if(space%5)return false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(state[i][j]=='.' && check(i-1, j) && check(i, j-1) && check(i+1, j) && check(i, j+1)){
                state[i][j] = '#';
                state[i-1][j] = '#';
                state[i][j-1] = '#';
                state[i+1][j] = '#';
                state[i][j+1] = '#';
            }
        }
    }
    if(space%5)return false;
    for(auto it : state){
        for(auto ch : it)
            if(ch=='.')
                return false;
    }
    return true;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    puts(find() ? "YES" : "NO");
}