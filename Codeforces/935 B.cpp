#include <bits/stdc++.h>
using namespace std;
map< pair<int, int>, bool>Map;
int n, ans=0, x, y;
string str;
int main()
{
    cin>>n;
    cin>>str;

    for(auto it : str){
        if(it=='R') x++;
        else y++;
        Map[make_pair(x, y)] = true;
    }
    for(int i=1; i<=n; i++){
        if(Map[make_pair(i+1, i)] && Map[make_pair(i-1, i)]) ans++;
        else if(Map[make_pair(i, i+1)] && Map[make_pair(i, i-1)]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

