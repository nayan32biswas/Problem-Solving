#include <bits/stdc++.h>
using namespace std;
#define Size 10003
int matrix[Size][Size], arr[Size];
vector< pair<int, int> >trans[Size];
void transpose(int &m, int &n){
    for(int i=0; i<m; i++){
        for(int j=0, k=0; j<n; j++)if(matrix[i][j]){
            trans[j].push_back(make_pair(matrix[i][j], i+1));
        }
    }
    swap(n, m);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int m, n, x;
    while(cin>>m>>n){
        for(int i=0; i<Size; i++) trans[i].clear();
        memset(matrix, 0, sizeof(matrix));
        for(int i=0; i<m; i++){
            scanf("%d", &x);
            for(int j=0; j<x; j++) scanf("%d", &arr[j]);
            for(int j=0; j<x; j++) scanf("%d", &matrix[i][arr[j]-1]);
        }
        transpose(m, n);
        cout<<m<<" "<<n<<endl;
        for(int i=0; i<m; i++){
            cout<<trans[i].size();
            for(auto v : trans[i])printf(" %d", v.second); puts("");
            int space = 0;
            for(auto v : trans[i]){
                if(space++) printf(" ");
                printf("%d", v.first);
            }
            puts("");
        }
    }
    return 0;
}
