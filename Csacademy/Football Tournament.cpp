#include <bits/stdc++.h>
using namespace std;
int mat[101][101];
int line[101];
int main()
{
    //freopen("input.txt", "r", stdin);
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) scanf("%d", &mat[i][j]);
    }

    for(int j=0; j<N; j++){
        for(int i=0; i<N; i++){
            if(mat[i][j]==1){
                line[i]++;
            }
            else {
                line[j]++;
            }
        }
    }

    int Max = -1, ans;
    for(int i=0; i<N; i++){
        if(line[i]>Max){
            Max = line[i];
            ans = i+1;
        }
    }
    cout<<ans<<endl;
}
