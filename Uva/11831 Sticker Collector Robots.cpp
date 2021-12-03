#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ppi;
string state[100], str;
int row, clm, len;
char deraction;
bool isValid(int x, int y) {
    return x>=0 && x<row && y>=0 && y<clm && state[x][y]!='#';
}
ppi Forword(ppi pos);
int main() {
    //freopen("input.txt", "r", stdin);
    while(scanf("%d%d%d", &row, &clm, &len) && row) {
        deraction = 0;
        ppi pos, temp;
        for(int i=0; i<row; i++) {
            cin>>state[i];
            if(!deraction) {
                pos.first = i;
                pos.second = 0;
                for(auto it : state[i]) {
                    if(it>='A' && it<='Z') {
                        deraction = it;
                        break;
                    }
                    pos.second++;
                }
            }
        }
        cin>>str;
        int ans = 0;
        for(auto it : str) {
            if(it=='F') {
                temp = Forword(pos);
                if(isValid(temp.first, temp.second)) {
                    pos = temp;
                    if(state[pos.first][pos.second]=='*') {
                        state[pos.first][pos.second] = '.';
                        ans++;
                    }
                }
            } else if(it=='E') {
                if(deraction=='N')
                    deraction = 'O';
                else if(deraction=='O')
                    deraction = 'S';
                else if(deraction=='S')
                    deraction = 'L';
                else
                    deraction = 'N';
            } else {
                if(deraction=='N')
                    deraction = 'L';
                else if(deraction=='L')
                    deraction = 'S';
                else if(deraction=='S')
                    deraction = 'O';
                else
                    deraction = 'N';
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
ppi Forword(ppi pos) {
    if(deraction=='N')
        pos = make_pair(pos.first-1, pos.second);
    if(deraction=='S')
        pos = make_pair(pos.first+1, pos.second);
    if(deraction=='L')
        pos = make_pair(pos.first, pos.second+1); // east
    if(deraction=='O')
        pos = make_pair(pos.first, pos.second-1); // west
    return pos;
}
