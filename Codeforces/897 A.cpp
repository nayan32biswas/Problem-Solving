#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, n, m;
    char c1, c2;
    string s;
    cin>>n>>m;
    cin>>s;
    while(m--){
        cin>>x>>y>>c1>>c2;
        x--, y--;
        for(; x<=y; x++)if(s[x]==c1)s[x] = c2;
    }
    cout<<s<<endl;

    return 0;
}
