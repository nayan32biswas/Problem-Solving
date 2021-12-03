#include <bits/stdc++.h>
using namespace std;
map<int, bool> M[4];
bool NUM(int n){
    if(n<10){
        if(M[0][n] || M[1][n] || M[2][n]) return 1;
        return 0;
    }
    int x = n%10; n/=10;
    for(int i=0, j; i<3; i++)if(M[i][n])
        for(j=0; j<3; j++)
            if(i!=j && M[j][x]) return 1;
    return 0;
}
int main()
{
    int i, j, x, n;
    cin>>n;
    for(i=0; i<n; i++)for(j=0; j<6; j++)cin>>x, M[i][x]=1;
    for(i=1; i<100; i++)if(!NUM(i))break;
    cout<<(--i)<<endl;
}
