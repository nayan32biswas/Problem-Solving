#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int>M;
    M["Tetrahedron"]=4;
    M["Cube"]=6;
    M["Octahedron"]=8;
    M["Dodecahedron"]=12;
    M["Icosahedron"]=20;
    int n, ans=0;
    cin>>n;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        ans+=M[s];
    }
    cout<<ans<<endl;
    return 0;
}
