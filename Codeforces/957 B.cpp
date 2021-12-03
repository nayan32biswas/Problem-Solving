#include <bits/stdc++.h>
using namespace std;
#define Size 50
string state[Size];
int main()
{
    //freopen("input.txt", "r", stdin);
    int row, clm;
    cin>>row>>clm;
    for(int i=0; i<row; i++) {
        cin>>state[i];
    }
    bool intr, same;
    for(int i=0; i<row; i++){
        for(int j=i+1; j<row; j++){
            same = intr = false;
            for(int k=0; k<clm; k++){
                if(state[i][k] != state[j][k]){
                    same = true;
                }
                if(state[i][k]=='#' && state[j][k]=='#'){
                    intr = true;
                }
            }
            if(same && intr)return puts("No"), 0;
        }
    }
    puts("Yes");
    return 0;
}
