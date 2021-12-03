#include <bits/stdc++.h>
using namespace std;
#define Size 1000
string str[Size];
int n, m;
bool isTrue(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

int Find(int x, int y){
    int up = 0, down=0, left=0, right=0;
    for(int i=x, j=y; isTrue(i, j) && str[i][j]=='B'; i--, up++);
    for(int i=x, j=y; isTrue(i, j) && str[i][j]=='B'; i++, down++);
    for(int i=x, j=y; isTrue(i, j) && str[i][j]=='B'; j--, left++);
    for(int i=x, j=y; isTrue(i, j) && str[i][j]=='B'; j++, right++);
    //cout<<up<<" "<<down<<" "<<left<<" "<<right<<endl;
    return min(up, min(down, min(left, right)));
}
int main()
{
    int Max=0, x, y;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>str[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(str[i][j]=='B'){
                int coun = Find(i, j);
                if(coun>Max){
                    Max = coun;
                    x = i+1;
                    y = j+1;
                }
            }
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
