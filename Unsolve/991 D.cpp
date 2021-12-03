#include <bits/stdc++.h>
using namespace std;
int stage[2][101];
void incre(int inc, int i){
    cout<<inc<<" "<<i<<endl;
    while(i>=0 && (stage[0][i]==1 || stage[1][i]==1)){
        if(stage[0][i]==1) stage[0][i]=inc;
        if(stage[1][i]==1) stage[1][i]==inc;
        i--;
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    string str[2];
    cin>>str[0]>>str[1];
    int len = str[0].size();
    for(int i=0; i<2; i++) {
        for(int j=0; j<len; j++) {
            if(str[i][j]=='X')
                stage[i][j]=0;
            else
                stage[i][j] = 1;
        }
    }
    int inc = 0;
    for(int i=0; i<len; i++) {
        if(stage[0][i]==1 || stage[1][i]==1) {
            if(stage[0][i]==1)inc++;
            if(stage[1][i]==1)inc++;
        } else {
            incre(inc, i);
            inc = 0;
        }
    }
    incre(inc, len-1);
    set<int>Set;
    for(int i=0; i<len; i++)cout<<stage[0][i]; puts("");
    for(int i=0; i<len; i++)cout<<stage[1][i]; puts("");

    return 0;
}

