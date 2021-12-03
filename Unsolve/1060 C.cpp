#include <bits/stdc++.h>
using namespace std;
#define Size 2005
typedef long long int lli;
vector<int>a, b;
vector< vector<lli> >matrix, aux;
void init(int N, int M){
    a.resize(N);
    b.resize(M);
    aux.resize(N);
    matrix.resize(N);
    for(int i=0; i<N; i++){
        aux[i].resize(M);
        matrix[i].resize(M);
    }
}
int preProcess() {
    int N = matrix.size(), M = matrix[0].size();
    for (int i=0; i<N; i++)
        aux[0][i] = matrix[0][i];
    for (int i=1; i<M; i++)
        for (int j=0; j<N; j++)
            aux[i][j] = matrix[i][j] + aux[i-1][j];
    for (int i=0; i<M; i++)
        for (int j=1; j<N; j++)
            aux[i][j] += aux[i][j-1];
}
int sumQuery(int tli, int tlj, int rbi, int rbj) {
    int res = aux[rbi][rbj];
    if(tli > 0)
        res = res - aux[tli-1][rbj];
    if(tlj > 0)
        res = res - aux[rbi][tlj-1];
    if(tli > 0 && tlj > 0)
        res = res + aux[tli-1][tlj-1];
    return res;
}
int demo(vector<int>temp) {
    temp.resize(8);
    temp[0] = 199;
}
int main() {
    //freopen("input.txt", "r", stdin);
    vector<int>temp;
    demo(temp);
    cout<<temp[0]<<endl;
    int n, m;
    scanf("%d%d", &n, &m);
    init(n, m);
    for(int i=0; i<n; i++)
        scanf("%lld", &a[i]);
    for(int i=0; i<m; i++)
        scanf("%lld", &b[i]);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            matrix[i][j] = a[i]*b[j];
            cout<<matrix[i][j]<<" ";
        }
        puts("");
    }
    preProcess();
    cout<<sumQuery(0, 0, 1, 1)<<endl;
    cout<<sumQuery(0, 0, 1, 2)<<endl;
    cout<<sumQuery(0, 1, 2, 2)<<endl;
    return 0;
}
