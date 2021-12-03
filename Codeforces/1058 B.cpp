#include <bits/stdc++.h>
using namespace std;
int n, d;
bool solve(){
    int x, y;
    cin>>x>>y;
    if(!(d<=(x+y) && (x+y)<=(2*n-d))) return false;
    if(!(-d<=(x-y) && (x-y)<=d)) return false;
    return true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int m;
    cin>>n>>d;
    cin>>m;
    while(m--){
        puts(solve() ? "YES" : "NO");
    }
    return 0;
}

